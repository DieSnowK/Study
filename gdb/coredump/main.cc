#include <iostream>

void func1(char *lp)
{
    // ½âÒı?¿ÕÖ¸Õë
    *lp = 10;
}

int main()
{
    char *lp = NULL;
    func1(lp);
    
    return 0;
}