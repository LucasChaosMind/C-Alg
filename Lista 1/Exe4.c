#include <stdio.h>
void func1(int x)
{
    x = 9 * x;
}
void func2(int v[])
{
    v[0] = 9 * v[0];
}
void main(void)
{
    int x, v[2];
    x = 111;
    v[0] = 111;

    func1(x);
    printf("x: %d\n", x);
    func2(v);
    printf("v[0]: %d\n", v[0]);
}
/**Não possuem por que x não é um ponteiro portanto as alteraçoes feitas na função func1 não modificam o valor da variavel**/
