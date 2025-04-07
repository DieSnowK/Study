#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return 0;
    }
    else if (pid == 0)
    {
        // child
        printf("child: pid = %d, ppid = %d\n", getpid(), getppid());
        for(int i = 0; i < 5; i++) 
        {
            printf("[child  print i] = %d\n", i);
            sleep(1);
        }
    }
    else
    {
        // parent
        printf("father: pid = %d, ppid = %d\n", getpid(), getppid());
        for(int j = 0; j < 5; j++) 
        {
            printf("[father print j] = %d\n", j);
            sleep(1);
        }
    }

    return 0;
}