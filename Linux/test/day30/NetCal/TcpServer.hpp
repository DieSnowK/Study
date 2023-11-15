#include <iostream>

class TcpServer
{
public:
    TcpServer(const uint16_t &port, const std::string &ip = "")
    {

    }

    void Start()
    {

    }

    
private:
    int _listensock;
    uint16_t _port;
    std::string _ip;
};