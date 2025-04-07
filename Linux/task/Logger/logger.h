#pragma once
#include <stdio.h>
#include <stdarg.h>

#define STD_BUFFER_SIZE 1024
#define LOGBUFFER_SIZE	4096

#define DEBUG	0
#define NORMAL	1
#define WARNING 2
#define ERROR	3
#define FATAL	4

// 我在平流层:P

#define LOG_DEBUG(format, ...) LogMessage(DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_NORMAL(format, ...) LogMessage(NORMAL, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_WARNING(format, ...) LogMessage(WARNING, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...) LogMessage(ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_FATAL(format, ...) LogMessage(FATAL, __FILE__, __LINE__, format, ##__VA_ARGS__)

void LogMessage(int level, const char* file, int line, const char* format, ...);