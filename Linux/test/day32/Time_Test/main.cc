#include <iostream>
#include <ctime>
#include <cassert>
#include <unistd.h>
#include <sys/time.h>

int main()
{
	while(true)
	{
		// 1.
		std::cout << "time:" << time(nullptr) << std::endl;

		// 2.
		struct timeval curtime = {0, 0};
		int n = gettimeofday(&curtime, nullptr);
		assert(n == 0);
		(void)n;
		std::cout << "gettimeofday:" << curtime.tv_sec << "." << curtime.tv_usec << std::endl;

		sleep(1);
	}
	return 0;
}