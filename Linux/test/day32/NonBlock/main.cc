#include <iostream>
#include <cstring>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>

bool SetNonBlock(int fd)
{
	int fl = fcntl(fd, F_GETFL); // 在底层获取当前fd对应的文件读写标志位
	if(fl < 0)
	{
		return false;
	}

	// 设置非阻塞
	fcntl(fd, F_SETFL, fl | O_NONBLOCK); // 在老的标志位的前提下新增内容
	return true;
}

int main()
{
	SetNonBlock(0);
	// 非阻塞的时候，以出错的形式返回，告知上层数据没有就绪
	// 但如何甄别是真的出错了，还是数据没有就绪？
	// 出错，不仅仅是错误返回值，errno也会被设置，表明出错原因

	char buffer[1024];
	while(true)
	{
		ssize_t s = read(0, buffer, sizeof(buffer) - 1);
		if(s > 0)
		{
			buffer[s - 1] = 0;
			std::cout << "echo# " << buffer << std::endl;
		}
		else
		{
			// 如果errno == 11，代表没出错，只是底层数据未就绪
			if(errno == EWOULDBLOCK || errno == EAGAIN)
			{
				std::cout << "当前fd未就绪" << std::endl;
			}
			else if(errno == EINTR)
			{
				std::cout << "当前IO可能被信号中断" << std::endl;
			}
			else
			{
				// 真的出错了，进行差错处理...
			}
		}

		sleep(1);
	}

	return 0;
}
