#include <stdio.h>
int main(void)
{
    int v[] = {10, 20, 30};
    int *p;
    p = v;
    p++;
    printf("%d\n", *p);
    return 0;
}
/**20**/
/**Seria 11**/
