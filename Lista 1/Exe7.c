#include <stdio.h>
void main(void)
{
    int v[3], *p, *a;
    p = v;
    *p = 10;
    *(p + 1) = 20;
    *(p + 2) = 30;
    a = &v[1];
    *a = 40;
    *(a - 1) = 50;
    printf("%d\n", v[0]);
    printf("%d\n", v[1]);
    printf("%d\n", v[2]);
}
/**Vai emprimir 50 40 30**/
