#pragma once

#include <iostream>
#include <ctime>

#define DEBUG   0
#define NOTICE  1
#define WARNING 2
#define ERROR   3

const std::string msg[] = {
    "DEBUG",
    "NOTICE",
    "WARNING",
    "ERROR"
};

std::ostream &Log(std::string message, int level)
{
    std::cout << "|" << time(nullptr) << "|" << msg[level] << "|" << message;
    return std::cout;
}