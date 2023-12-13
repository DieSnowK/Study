#include <iostream>
#include <cstring>
#include <sys/epoll.h>

class Epoll
{
private:
    const static int gsize = 256; // 这里是多少无所谓，该参数已经被废弃
public:
    static int CreateEpoll()
    {
        int epfd = epoll_create(gsize);
        if(epfd < 0)
        {
            std::cout << strerror(errno);
            exit(5);
        }
        return epfd;
    }

    static bool CtlEpoll(int epfd, int op, int fd, uint32_t events)
    {
        struct epoll_event ev;
        ev.events = events;
        ev.data.fd = fd;

        return epoll_ctl(epfd, op, fd, &ev) == 0;
    }

    static int WaitEpoll(int epfd, struct epoll_event *revs, int num, int timeout)
    {
        // 细节1.如果底层就绪的sock非常多，revs承装不下，怎么办？
            // 不影响，一次拿不完，那就下一次再拿
        // 细节2.关于epoll_wait的返回值问题：有几个fd上的事件就绪，就返回几
        // epoll返回的时候，会将所有的event按照顺序放入到revs数组中，一共有返回值个
        return epoll_wait(epfd, revs, num, timeout);
    }
};