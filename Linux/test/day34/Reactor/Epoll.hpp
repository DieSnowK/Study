#include <iostream>
#include <sys/epoll.h>

class Epoll
{
    const static int g_timeout = 5000;
    const static int g_size = 256;

public:
    Epoll(const int timeout = g_timeout)
    {}

    void CreateEpoll()
    {
        _epfd = epoll_create(g_size);
        if(_epfd < 0)
        {
            exit(5);
        }
    }

private:
    int _epfd;
    int _timeout;
};