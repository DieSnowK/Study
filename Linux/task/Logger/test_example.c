#define _CRT_SECURE_NO_WARNINGS
#include "logger.h"


int main()
{
	char* LYL = "WSL";
	int age = 18;
	double weight = 144.5;

	LOG_DEBUG("我是 %s, 年龄: %d, 体重: %5.2f", LYL, age, weight);
	LOG_NORMAL("我是 %s, 年龄: %d, 体重: %5.2f", LYL, age, weight);
	LOG_WARNING("我是 %s, 年龄: %d, 体重: %5.2f", LYL, age, weight);
	LOG_ERROR("我是 %s, 年龄: %d, 体重: %5.2f", LYL, age, weight);
	LOG_FATAL("我是 %s, 年龄: %d, 体重: %5.2f", LYL, age, weight);

	return 0;
}