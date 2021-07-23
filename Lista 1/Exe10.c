#include <stdio.h>

int main (){

    int vet[3]={10,20,30};

    for(int i=0;i<3;i++){
        printf("%d\t",*(vet+i));
    }
}
