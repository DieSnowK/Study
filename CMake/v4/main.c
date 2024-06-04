#include <stdio.h>
#define NUMBER  3

int main()
{
    int a = 10;
#ifdef DEBUG
    printf("Pikachu~\n");
#endif
    for(int i=0; i<NUMBER; ++i)
    {
        printf("DieSnowK\n");
    }
    return 0;
}