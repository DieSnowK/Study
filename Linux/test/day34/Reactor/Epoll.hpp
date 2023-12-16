#include <iostream>
#include <sys/epoll.h>

class Epoll
{
    const static int g_timeout = 5000;
    const static int g_size = 256;

public:
    Epoll(const int timeout = g_timeout)
    : _timeout(timeout)
    {}

    ~Epoll()
    {
        close(_epfd);
    }

    void CreateEpoll()
    {
        _epfd = epoll_create(g_size);
        if(_epfd < 0)
        {
            exit(5);
        }
    }

    bool AddSockToEpoll(int sock, uint32_t events)
    {
        struct epoll_event ev;
        ev.events = events;
        ev.data.fd = sock;

        return (epoll_ctl(_epfd, EPOLL_CTL_ADD, sock, &ev) == 0);
    }

    int WaitEpoll(struct epoll_event *revs, int revs_num)
    {
        return epoll_wait(_epfd, revs, revs_num, _timeout);
    }

    bool CtrlEpoll(int sock, uint32_t events)
    {
        events |= EPOLLET;
        struct epoll_event ev;
        ev.events = events;
        ev.data.fd = sock;
        return (epoll_ctl(_epfd, EPOLL_CTL_MOD, sock, &ev) == 0);
    }

    bool DelFromEpoll(int sock)
    {
        return (epoll_ctl(_epfd, EPOLL_CTL_DEL, sock, nullptr) == 0);
    }

private:
    int _epfd;
    int _timeout;
};