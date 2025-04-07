#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_startA(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        printf("[thread_startA]: %d\n", i);
        sleep(1);
    }
    return NULL;
}

void *thread_startB(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        printf("[thread_startB]: %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid_a, tid_b;
    if (pthread_create(&tid_a, NULL, thread_startA, NULL) < 0)
    {
        perror("pthread_create");
        return 0;
    }

    if (pthread_create(&tid_b, NULL, thread_startB, NULL) < 0)
    {
        perror("pthread_create");
        return 0;
    }

    pthread_join(tid_a, NULL);
    pthread_join(tid_b, NULL);

    return 0;
}