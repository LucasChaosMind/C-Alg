#include <stdio.h>

int main (){

    int a=10,b=5,*x,*y;

    x= &a;
    y= &b;

    printf("%d",((*x)+*y));
}
