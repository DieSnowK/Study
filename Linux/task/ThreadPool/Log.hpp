#pragma once

#include <iostream>
#include <cstdarg>
#include <ctime>

// 日志是有日志级别的
#define DEBUG   0
#define NORMAL  1
#define WARNING 2
#define ERROR   3s
#define FATAL   4

// 映射表
const char *gLevelMap[] =
{
    "DEBUG",
    "NORMAL",
    "WARNING",
    "ERROR",
    "FATAL"
};

#define LOGFILE "./threadpool.log"

// 完整的日志功能，至少要包括：
// 日志等级 时间 支持用户自定义(日志内容 文件行 文件名)
void LogMessage(int level, const char *format, ...)
{
#ifndef DEBUG_SHOW
    if(level == DEBUG)
    {
        return;
    }
#endif

    char stdBuffer[1024]; // 标准部分
    time_t timestamp = time(nullptr);
    snprintf(stdBuffer, sizeof stdBuffer, "[%s] [%ld]", gLevelMap[level], timestamp);

    char logBuffer[1024]; // 自定义部分
    va_list args;
    va_start(args, format);
    vsnprintf(logBuffer, sizeof logBuffer, format, args);
    va_end(args);

    printf("%s %s\n", stdBuffer, logBuffer);
}