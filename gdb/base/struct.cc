#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int a;
    int b;
};

int main()
{
    struct Data *lp = (struct Data*)malloc(sizeof(struct Data));
    lp->a = 10;
    lp->b = 20;
    printf("lp->a: %d, lp->b: %d\n", lp->a, lp->b);

    struct Data aa;
    aa.a = 100;
    aa.b = 200;
    printf("aa.a : %d, aa.b : %d\n", aa.a, aa.b);

    free(lp);
    return 0;
}