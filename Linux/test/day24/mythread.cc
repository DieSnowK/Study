#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;



// 1.��ʶpthread�⣬������һ�δ�����bug
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
//         sleep(1); // ���⴫��bug
//     }

//     return 0;
// }