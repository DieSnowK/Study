#include "comm.hpp"

int main()
{
    // 1.获取管道文件
    int fd = open(ipcPath.c_str(), O_WRONLY);
    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    // 2.ipc过程
    string buffer;
    while(true)
    {
        cout << "Please Enter Message Line:> ";
        std::getline(std::cin, buffer);
        write(fd, buffer.c_str(), buffer.size());
    }

    close(fd);
    return 0;
}