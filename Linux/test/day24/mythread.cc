#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

// // 2.线程分离实操
// // 线程分离之后就不能join此线程了
// void *threadRoutine(void *args)
// {
//     pthread_detach(pthread_self());

//     sleep(5);

//     return (void *)233;
// }


// int main()
// {
//     pthread_t tid;                                             
//     pthread_create(&tid, nullptr, threadRoutine, (void *)"thread 1");

//     int count = 0;
//     while (true)
//     {
//         sleep(1);
//         if (++count == 8)
//         {
//             break;
//         }
//     }

//     return 0;
// }

// // 2.线程空间问题
// // int g_val = 100;
// __thread int g_val = 100; // 修饰全局变量，带来的结果是让每一个线程各自拥有一个全局的变量  --  线程的局部存储

// void *threadRoutine(void *args)
// {
//     int count = 0;
//     while (true)
//     {
//         cout << (char *)args << " : " << g_val++ << " &：" << &g_val << endl;
//         sleep(1);

//         if (++count == 5)
//         {
//             break;
//         }
//     }

//     return (void *)233; // 返回给主线程
// }

// int main()
// {
//     pthread_t tid;                                                   
//     pthread_create(&tid, nullptr, threadRoutine, (void *)"thread 1");

//     int count = 0;
//     while (true)
//     {
//         cout << g_val << " &：" << &g_val << endl;
//         sleep(1);
//         if (++count == 5)
//         {
//             break;
//         }
//     }

//     int *ret = nullptr;
//     pthread_join(tid, (void **)&ret); // 默认会阻塞等待新线程退出

//     cout << "main thread wait done" << endl;
//     cout << "new thread retval：" << (long long)(ret) << endl;

//     return 0;
// }

// // 2.线程终止实操  -->  pthread_exit() && pthread_cancle
// void *threadRoutine(void *args)
// {
//     int count = 0;
//     while (true)
//     {
//         cout << "new thread：" << (char *)args << " running..." << endl;
//         sleep(1);

//         if (++count == 5)
//         {
//             break;
//         }
//     }

//     // pthread_exit((void *)666);
//     return (void *)233; // 返回给主线程
// }

// int main()
// {
//     pthread_t tid;                                                    
//     pthread_create(&tid, nullptr, threadRoutine, (void *)"thread 1");

//     int count = 0;
//     while (true)
//     {
//         sleep(1);
//         if (++count == 2)
//         {
//             break;
//         }
//     }

//     // 线程被取消，join的时候，退出码是-1
//     // #define PTHREAD_CANCELED ((void *) -1)
//     pthread_cancel(tid);

//     int *ret = nullptr;
//     pthread_join(tid, (void **)&ret); // 默认会阻塞等待新线程退出

//     cout << "main thread wait done" << endl;
//     cout << "new thread retval：" << (long long)(ret) << endl;

//     return 0;
// }

// // 1.线程返回值实操
// void *threadRoutine(void* args)
// {
//     int count = 0;
//     int *data = new int[5];
//     while (true)
//     {
//         cout << "new thread：" << (char *)args << " running..." << endl;
//         data[count] = count;
//         sleep(1);

//         if(++count == 5)
//         {
//             break;
//         }
//     }

//     return (void *)data; // 返回给主线程
// }

// int main()
// {
//     pthread_t tid; // 本质是一个地址
//     pthread_create(&tid, nullptr, threadRoutine, (void *)"thread 1"); // 设置nullptr表示使用默认属性

//     int *ret = nullptr;
//     pthread_join(tid, (void **)&ret); // 默认会阻塞等待新线程退出

//     cout << "main thread wait done" << endl;
//     // cout << "new thread retval：" << (long long)(ret) << endl;
//     for (int i = 0; i < 5; i++)
//     {
//         cout << "ret " << i << " : " << ret[i] << endl;
//     }

//     return 0;
// }