#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG_MODE
# include "logger.h"

// 明确: 虽说我们是自己做一个日志器，但是实际上，也是在他人的封装基础上
	// *printf()

// level: 标识日志等级
	// 信息也是要去做区分的
		// eg.INFO FATAL ERROR DEBUG
	// 同时，有些信息，是在不同的场合，我们是需要舍去的
		// 但是，食之无味，弃之可惜，如果下次还需要用到，可能就会同样的代码来回写
	// 区分日志等级，加上条件编译，就可以实现类似于"DEBUG"日志开关类似的功能
		// 这里我还会带你使用命令行传参

// format: 格式处理

// ... -> 可变参数列表

//const char* gLevelMap[] ={"DEBUG","NORMAL","WARNING","ERROR","FATAL"};
const char* gLevelMap[] =
{
	"DEBUG",
	"NORMAL",
	"WARNING",
	"ERROR",
	"FATAL"
};


// 我在第一层:)
void LogMessage(int level, const char* file, int line, const char* format, ...)
{
	// 1.条件编译
#ifndef DEBUG_MODE
	if (level == DEBUG)
	{
		return;
	}
#endif
	// 2.标准部分 -> 打死不变
	char stdBuffer[STD_BUFFER_SIZE];
	snprintf(stdBuffer, STD_BUFFER_SIZE, "[LYL's Logger][%-7s][%s:%d]:", gLevelMap[level], file, line); // [LYL's Logger][DEBUG]: 

	// 3.自定义部分 -> 用户自定义的内容，用起来类似于printf()
	char logBuffer[LOGBUFFER_SIZE];

	va_list args;
	va_start(args, format);
	// format [x, y, z]
	//         | 
	vsnprintf(logBuffer, LOGBUFFER_SIZE, format, args);

	printf("%s [%s]\n", stdBuffer, logBuffer);

}