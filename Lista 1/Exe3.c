#include <stdio.h>

int main(void)
{
    int x, *p;
    x = 10;
    p = &x;

    printf("%d",*p);
}
