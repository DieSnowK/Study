#include <iostream>

void func2()
{
    for (int i = 0; i < 5; i++)
    {
        printf("i=%d\n", i);
    }
}

void func1()
{
    func2();
}

int main()
{
    func1();
    return 0;
}