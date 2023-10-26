#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;



// 1.初识pthread库，但是这一段代码有bug
// void *threadRun(void *args)
// {
//     const string name = (char *)args;
//     while (true)
//     {
//         cout << name << " pid: " << getpid() << endl;
//         sleep(1);
//     }

//     return nullptr;
// }

// int main()
// {
//     pthread_t tid[5];
//     char name[64];
//     for (int i = 0; i < 5; i++)
//     {
//         snprintf(name, sizeof name, "%s-%d", "thread", i);
//         pthread_create(tid + i, nullptr, threadRun, (void *)name);
//         sleep(1); // 缓解传参bug
//     }

//     return 0;
// }