#include <iostream>
#include <cstring>
#include <sys/epoll.h>

class Epoll
{
private:
    const static int gsize = 256; // �����Ƕ�������ν���ò����Ѿ�������
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
        // ϸ��1.����ײ������sock�ǳ��࣬revs��װ���£���ô�죿
            // ��Ӱ�죬һ���ò��꣬�Ǿ���һ������
        // ϸ��2.����epoll_wait�ķ���ֵ���⣺�м���fd�ϵ��¼��������ͷ��ؼ�
        // epoll���ص�ʱ�򣬻Ὣ���е�event����˳����뵽revs�����У�һ���з���ֵ��
        return epoll_wait(epfd, revs, num, timeout);
    }
};