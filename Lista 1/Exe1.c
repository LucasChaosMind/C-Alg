#include <stdio.h>
#include <string.h>
void main(void)
{
    int v[] = {1, 2, 3, 4, 5};
    char s[] = "ola";
    int i = 0;
    for(i = 0; i < 5; i++)
    {
        printf("valor: %d, end.: %ld\n", v[i], &v[i]);
    }
    printf("\n");
    for(i = 0; i < strlen(s); i++)
    {
        printf("valor: %c, end.: %ld\n", s[i], &s[i]);
    }
}
/**Por que um int vale 4 bits logo quanto vc incrementa ela vai um
 4 bits para frente na memoria, ja o char vale 1 bits então ele anda 1 bits
 na memoria**/

