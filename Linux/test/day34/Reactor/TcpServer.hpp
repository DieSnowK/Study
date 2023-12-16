#include "Sock.hpp"
#include "Log.hpp"
#include "Epoll.hpp"
#include "Protocol.hpp"
#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

class TcpServer; // 声明
class Connection; // 声明

using func_t = std::function<void(Connection *)>;
using callback_t = std::function<void(Connection *, std::string &request)>;

// 为了能够正常工作，常规的sock必须要有自己的接收&&发送缓冲区
struct Connection
{
    Connection(int sock = -1)
    : _sock(sock)
    , _tsvr(nullptr)
    // , _lasttimestamp() // TODO
    {}

    ~Connection()
    {}

    void SetCallBack(func_t recv_cb, func_t send_cb, func_t except_cb)
    {
        _recv_cb = recv_cb;
        _send_cb = send_cb;
        _except_cb = except_cb;
    }

    // 负责IO的fd
    int _sock;

    // 回调方法，表征的就是对_sock特定读写对应的方法
    func_t _recv_cb;
    func_t _send_cb;
    func_t _except_cb;

    // 接收&&发送缓冲区
    std::string _inbuffer;
    std::string _outbuffer;

    // 设置对TcpServer的回调指针
    TcpServer *_tsvr;

    // 时间戳
    uint32_t _lasttimestamp; // TODO 选做
};

class TcpServer
{
    const static uint16_t g_port = 8080;
    const static int g_num = 100;

public:
    TcpServer(callback_t cb, int num = g_num, const uint16_t port = g_port)
    : _port(port)
    , _revs_num(num)
    , _cb(cb)
    {
        // 1.创建_listensock
        _listensock = Sock::Socket();
        Sock::Bind(_listensock, _port);
        Sock::Listen(_listensock);

        // 2.创建多路转接对象
        _poll.CreateEpoll();

        // 3.添加_listensock到服务器中
        AddConnection(_listensock, std::bind(&TcpServer::Accepter, this, std::placeholders::_1), nullptr, nullptr);

        // 4.构建一个获取就绪事件的缓冲区
        _revs = new struct epoll_event[_revs_num];
    }

    ~TcpServer()
    {
        if(_listensock >= 0)
        {
            close(_listensock);
        }

        if(_revs)
        {
            delete[] _revs;
        }
    }

    void Dispatcher()
    {
        while(true)
        {
            LoopOnce();
        }
    }

    void EnableReadWrite(Connection *conn, bool readable, bool writeable)
    {
        uint32_t events = (readable ? EPOLLIN : 0) | (writeable ? EPOLLOUT : 0);
        _poll.CtrlEpoll(conn->_sock, events);
    }

private:
    void LoopOnce()
    {
        int n = _poll.WaitEpoll(_revs, _revs_num);
        for (int i = 0; i < n; i++)
        {
            int sock = _revs[i].data.fd;
            uint32_t revents = _revs[i].events;

            // 将所有的异常，全部交给read/write来统一处理，由其调用到Excepter()
            if(revents & EPOLLERR)
            {
                revents |= (EPOLLIN | EPOLLOUT);
            }

            if(revents & EPOLLHUP)
            {
                revents |= (EPOLLIN | EPOLLOUT);
            }

            if(revents & EPOLLIN)
            {
                if(IsConnectionExist(sock) && _connections[sock]->_recv_cb)
                {
                    _connections[sock]->_recv_cb(_connections[sock]);
                }
            }

            if(revents & EPOLLOUT)
            {
                if (IsConnectionExist(sock) && _connections[sock]->_send_cb)
                {
                    _connections[sock]->_send_cb(_connections[sock]);
                }
            }
        }
    }
    // 专门针对任意sock进行添加至TcpServer
    void AddConnection(int sock, func_t recv_cb, func_t send_cb, func_t except_cb)
    {
        // 0.设置fd非阻塞
        Sock::SetNonBlock(sock);

        // 除了_listensock，未来会存在大量的socket，每一个sock都必须被封装成一个Connection
        // 当服务器中存在大量的Connection的时候，TcpServer就需要将所有的Connection进行管理

        // 1.构建coon对象，封装sock
        Connection *conn = new Connection(sock);
        conn->SetCallBack(recv_cb, send_cb, except_cb);
        conn->_tsvr = this;
        // conn->_lasttimestamp = time(); // TODO

        // 2.sock添加到epoll中
        _poll.AddSockToEpoll(sock, EPOLLIN | EPOLLET); // 任何多路转接的服务器，一般默认只会打开对读取时间的关心，写入事件会按需打开

        // 3.将对应的Connection*添加到Connection映射表中
        _connections.insert({sock, conn}); // C++11中的列表初始化
    }

    void Accepter(Connection* conn)
    {
        // 无法保证底层只有一个连接就绪，所以轮询读取
        while (true)
        {
            std::string clientip;
            uint16_t clientport;
            int accept_errno; // 用此变量是防止多线程下，errno被覆盖

            int sock = Sock::Accept(conn->_sock, &clientip, &clientport, &accept_errno);
            if(sock < 0)
            {
                if (accept_errno == EAGAIN || accept_errno == EWOULDBLOCK)
                {
                    break; // 已经读干净了
                }
                else if(accept_errno == EINTR)
                {
                    continue; // 被信号打断，概率非常低
                }
                else
                {
                    // accept失败
                    LogMessage(WARNING, "accept error, %s", strerror(accept_errno));
                    break;
                }
            }

            // 将sock托管给epoll，加入TcpServer
            AddConnection(sock, std::bind(&TcpServer::Recver, this, std::placeholders::_1),
                          std::bind(&TcpServer::Sender, this, std::placeholders::_1),
                          std::bind(&TcpServer::Excepter, this, std::placeholders::_1));
        } // end of while(true)
    } // end of Accepter

    void Recver(Connection* conn)
    {
        // TODO 更新最近访问时间

        const int num = 1024;
        bool err = false;

        while (true)
        {
            char buffer[1024];
            ssize_t n = recv(conn->_sock, buffer, sizeof(buffer) - 1, 0);
            if(n < 0)
            {
                if(errno == EAGAIN || errno == EWOULDBLOCK)
                {
                    break; // 正常读完
                }
                else if(errno == EINTR)
                {
                    continue;
                }
                else
                {
                    LogMessage(ERROR, "recv error, %s", strerror(errno));
                    conn->_except_cb(conn);
                    err = true;
                    break;
                }
            }
            else if(n == 0)
            {
                LogMessage(NORMAL, "client[%d] quit, server close it :P", conn->_sock);
                conn->_except_cb(conn);
                err = true;
                break;
            }
            else
            {
                // 读取成功
                buffer[n] = 0;
                conn->_inbuffer += buffer;
            }
        } // end of while(true)
        LogMessage(DEBUG, "conn->_inbuffer[sock:%d]: %s", conn->_sock, conn->_inbuffer.c_str());

        if(!err)
        {
            std::vector<std::string> msgs;
            SpliteMessage(conn->_inbuffer, &msgs);

            // 到这里能保证，获得一定都是完整报文
            for(auto &msg : msgs)
            {
                _cb(conn, msg); // 这里可以将msg封装成task，然后push到任务队列，任务处理交给后端线程池
            }
        }
    } // end of Recver

    // 最开始的时候，conn是没有被触发写事件的，需要上层发起调用
    void Sender(Connection *conn)
    {
        while(true)
        {
            ssize_t n = send(conn->_sock, conn->_outbuffer.c_str(), conn->_outbuffer.size(), 0);
            if(n > 0)
            {
                conn->_outbuffer.erase(0, n);
                if(conn->_outbuffer.empty())
                {
                    break;
                }
            }
            else
            {
                if(errno == EAGAIN || errno == EWOULDBLOCK)
                {
                    break;
                }
                else if(errno == EINTR)
                {
                    continue;
                }
                else
                {
                    LogMessage(ERROR, "send error, %s", strerror(errno));
                    conn->_except_cb(conn);
                    break;
                }
            }

            // 无法确定是否发完，但是可以保证，如果没有出错，一定要么发完，要么发送条件不满足，下次发送
            // 根据输出缓冲区是否为空，设置epoll事件的读写状态
            if(conn->_outbuffer.empty())
            {
                EnableReadWrite(conn, true, false); // 全部发完，则此sock下次只关心read
            }
            else
            {
                EnableReadWrite(conn, true, true); // 未发完，则此sock还要继续关心read/write
            }
        } // end of while(true)
    } // end of Sender

    void Excepter(Connection *conn)
    {
        int sock = conn->_sock;

        // 1.从epoll中移除
        bool ret = _poll.DelFromEpoll(conn->_sock);
        assert(ret); // 要判断，可以改成if
        (void)ret;

        // 2.从_connections移除
        _connections.erase(conn->_sock);

        // 3.
        close(conn->_sock);

        // 4.
        delete conn;

        LogMessage(NORMAL, "Excepter 已回收完毕[%d]的异常情况", sock);
    }

    // 为什么需要此接口？
    // 未来服务器可能存在大量异常情况
    // 有可能事件存在，但是连接对应的Connection* 已经被释放了
    bool IsConnectionExist(int sock)
    {
        auto iter = _connections.find(sock);
        if(iter == _connections.end())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
private:
    int _listensock;
    uint16_t _port;
    Epoll _poll;
    struct epoll_event *_revs; // 用于存放就绪事件
    int _revs_num;
    std::unordered_map<int, Connection *> _connections;
    callback_t _cb; // 上层的业务处理
};