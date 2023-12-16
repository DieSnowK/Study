#include "TcpServer.hpp"
#include <map>
#include <memory>

// 以后有新的计算类别时，直接往map里注册即可
static std::map<char, std::function<void(int, int, Response &)>> opFuncMap =
    {
        // 初始化列表 + initializer_list + lambda
        {'+', [](int a, int b, Response &resp)
         {
             resp._ret = a + b;
         }},

        {'-', [](int a, int b, Response &resp)
         {
             resp._ret = a - b;
         }},

        {'*', [](int a, int b, Response &resp)
         {
             resp._ret = a * b;
         }},

        {'/', [](int a, int b, Response &resp)
         {
             if (b == 0)
             {
                 resp._code = 1;
                 return;
             }
             resp._ret = a / b;
         }},

        {'%', [](int a, int b, Response &resp)
         {
             if (b == 0)
             {
                 resp._code = 2;
                 return;
             }
             resp._ret = a % b;
         }},
}; // end of opFuncMap

static Response Calculator(Request &req)
{
    Response resp(0, 0);
    opFuncMap[req._op](req._x, req._y, resp);
    return resp;
}

void NetCal(Connection* conn, std::string request)
{
    LogMessage(DEBUG, "NetCal get request: %s", request.c_str());

    // 1.反序列化
    Request req;
    if(!req.DeSerialize(request))
    {
        return;
    }

    // 2.业务处理
    Response resp = Calculator(req);

    // 3.序列化，构建应答
    std::string sendstr = resp.Serialize();
    sendstr = Encode(sendstr);

    // 4.交给服务器conn
    conn->_outbuffer += sendstr;

    // 5.想办法，让底层的TcpServer开始发送
    // a.需要有完整的发送逻辑  
    // b.触发发送动作，一旦开启EPOLLOUT，epoll会立马自动立马触发一次发送事件就绪，如果后续保持发送的开启，epoll会一直发送
    conn->_tsvr->EnableReadWrite(conn, true, true);
}

int main()
{
    std::unique_ptr<TcpServer> svr(new TcpServer(NetCal));
    svr->Dispatcher();
    return 0;
}