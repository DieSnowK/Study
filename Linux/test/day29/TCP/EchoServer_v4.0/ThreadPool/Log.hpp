#pragma once

#include <iostream>
#include <cstdarg>
#include <ctime>

// ��־������־�����
#define DEBUG   0
#define NORMAL  1
#define WARNING 2
#define ERROR   3
#define FATAL   4

// ӳ���
const char *gLevelMap[] =
{
    "DEBUG",
    "NORMAL",
    "WARNING",
    "ERROR",
    "FATAL"
};

#define LOGFILE "./threadpool.log"

// ��������־���ܣ�����Ҫ������
// ��־�ȼ� ʱ�� ֧���û��Զ���(��־���� �ļ��� �ļ���)
void LogMessage(int level, const char *format, ...)
{
#ifndef DEBUG_SHOW
    if(level == DEBUG)
    {
        return;
    }
#endif

    char stdBuffer[1024]; // ��׼����
    time_t timestamp = time(nullptr);
    snprintf(stdBuffer, sizeof stdBuffer, "[%s] [%ld]", gLevelMap[level], timestamp);

    char logBuffer[1024]; // �Զ��岿��
    va_list args;
    va_start(args, format);
    vsnprintf(logBuffer, sizeof logBuffer, format, args);
    va_end(args);

    printf("%s %s\n", stdBuffer, logBuffer);
}