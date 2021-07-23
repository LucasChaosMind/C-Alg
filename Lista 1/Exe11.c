#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (){

    char str[]="Bom dia!";
    char *s,aux[strlen(str)];
    s = aux;


    printf("%s",*s);
}
