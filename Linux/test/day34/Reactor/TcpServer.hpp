#include "Sock.hpp"
#include "Log.hpp"
#include "Epoll.hpp"
#include <string>
#include <unordered_map>
#include <functional>

class TcpServer; // 声明
class Connection; // 声明

using func_t = std::function<void(Connection *)>;

// 为了能够正常工作，常规的sock必须要有自己的接收&&发送缓冲区
class Connection
{
public:
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

private:
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

public:
    TcpServer(const uint16_t port = g_port)
    : _port(port)
    {
        // 1.创建_listensock
        _listensock = Sock::Socket();
        Sock::Bind(_listensock, _port);
        Sock::Listen(_listensock);

        // 2.创建多路转接对象
        _poll.CreateEpoll();

        // 3.添加_listensock到服务器中
        AddConnection(_listensock); // TODO

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

    }

private:
    // 专门针对任意sock进行添加至TcpServer
    void AddConnection(int sock, func_t recv_cb, func_t send_cb, func_t except_cb)
    {

    }

private:
    int _listensock;
    uint16_t _port;
    Epoll _poll;
    struct epoll_event *_revs; // 用于存放就绪事件
    int _revs_num;
    std::unordered_map<int, Connection *> _connections;
};