#include <iostream>

void func1(char *lp)
{
    // ����?��ָ��
    *lp = 10;
}

int main()
{
    char *lp = NULL;
    func1(lp);
    
    return 0;
}