#include <iostream>

void func1(char *lp)
{
    // 解引?空指针
    *lp = 10;
}

int main()
{
    char *lp = NULL;
    func1(lp);
    
    return 0;
}