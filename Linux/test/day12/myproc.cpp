#include <iostream>
#include <unistd.h>

int main()
{
	std::cout << "进程从这里开始" << std::endl;
	execl("/usr/bin/ls", "ls", "--color=auto", "-l", "-a", NULL); // 必须以NULL参数结尾
	//execl("user/bin/ls", "ls", "-l", "-a",NULL); // 找不到时，会返回
	std::cout << "进程从这里结束" << std::endl;
	return 0;
}
