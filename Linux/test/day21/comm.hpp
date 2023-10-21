#include <iostream>
#include <cstdio>
#include <cassert>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "Log.hpp"

using namespace std;

#define PATH_NAME "/home/snowk"
#define PROJ_ID 0x233
#define SHM_SIZE 4096 // 共享内存大小，最好是页(PAGE:4096)整数倍