#pragma once
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "Log.hpp"

using namespace std;

#define MODE 0666
#define SIZE 128

string ipcPath = "./fifo.ipc";