#include <stdio.h>
#include <string.h>

int main()
{
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("arr[%lu]=%d\n", i, arr[i]);
    }

    return 0;
}