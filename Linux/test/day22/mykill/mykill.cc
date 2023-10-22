#include <iostream>
#include <string>
#include <sys/types.h>
#include <signal.h>

using namespace std;

void Usage(string proc)
{
    cout << "Usage:\n\t" << proc << " SIGNUM PID" << endl;
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }

    int signum = atoi(argv[1]);
    int pid = atoi(argv[2]);

    kill(pid, signum);
    
    return 0;
}