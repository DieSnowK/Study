#pragma once

#include "Log.hpp"
#include "Sock.hpp"
#include <iostream>
#include <sys/select.h>
#include <sys/time.h>

#define BITS 8
#define NUM (sizeof(fd_set)*BITS)
#define FD_NONE -1

class SelectServer
{
    struct timeval o_233;

private:
    int _listensock;
    uint16_t _port;
    int _fd_Array[NUM];
    // 此处可以用vector，会更加方便
    // 但为了后续说明select问题，故用原生数组
};