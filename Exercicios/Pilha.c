#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct item Item;
typedef struct pilha Pilha;


struct item{
    int chave;
    //Demais campos
};

struct pilha {
    Item item[MAXTAM];
    int topo;
};

Pilha *criaPilhaVazia() {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

//retorna 1 se a pilha está cheia ou 0 se não está cheia
int verificaPilhaCheia(Pilha *p) {
    return p->topo == MAXTAM - 1;
}

//adiciona um elemento no fim da pilha
void empilha(Pilha *p,int chave) {
    if (verificaPilhaCheia(p)) {
        printf("Erro: a pilha esta cheia.\n");
        return;
    }

    Item novoItem;
    novoItem.chave = chave;
    p->topo++;
    p->item[p->topo] = novoItem;
}

//imprime a pilha
void imprimePilha(Pilha *p) {
    int tam = p->topo + 1;
    int i;
    for (i = 0; i < tam; i++) {
        printf("Chave: %d \n", p->item[i].chave);
    }
}

//remove um item qualquer da pilha
void desempilha(Pilha *p) {
    if (verificaPilhaVazia(p)) {
        printf("Erro: a pilha está vazia.\n");
        return;
    }
    p->topo--;
}

//retorna 1 se a Pilha está vazia ou 0 se não está vazia
int verificaPilhaVazia(Pilha *p) {
    return p->topo == -1;
}

//libera da memória
void liberaPilha(Pilha *p) {
    free(p);
}
