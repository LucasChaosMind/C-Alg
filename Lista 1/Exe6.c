#include <stdio.h>
#include <string.h>

void imprime(char *s, int n)
{
    char *c;
    for (c = s; c < s + n; c++)
        printf ("%c", *c);
}
void main(void)
{
    char s[] = "bom dia";
    imprime(s, strlen(s));
}
/**Esta imprimindo a a string s*/
