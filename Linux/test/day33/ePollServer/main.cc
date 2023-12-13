#include "EpollServer.hpp"
#include <memory>

void Echo(std::string request)
{
    // �˴���ɷ�����ҵ���߼�
    std::cout << "Client# " << request << std::endl;
}

int main()
{
    std::unique_ptr<EpollServer> svr(new EpollServer(Echo));
    svr->Start();

    return 0;
}