#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct item Item;
typedef struct fila Fila;


#define MAXTAM 7


struct item {
    char chave;
    //Demais
};

struct fila{
    Item item[MAXTAM];
    int primeiro;
    int ultimo;
    int tamanho;
};

Fila *criaFilaVazia() {
    Fila *f = malloc(sizeof(Fila));
    f->primeiro = 0;
    f->ultimo = 0;
    f->tamanho = 0;
    return f;
}

//retorna 1 se a fila está cheia ou 0 se não está cheia
int verificaFilaCheia(Fila *f) {
    return f->tamanho == MAXTAM;
}

//adiciona um elemnto no fim da fila
void enfileira(Fila *f, char chave) {
    if (verificaFilaCheia(f)) {
        printf("Erro: a fila esta cheia. \n");
        return;
    }
    Item novoItem;
    novoItem.chave = chave;
    f->item[f->ultimo] = novoItem;
    f->ultimo = (f->ultimo + 1) % MAXTAM;
    f->tamanho++;
}

//imprime a fila
void imprimeFila(Fila *f) {
    int t;
    int i = f->primeiro;
    for (t = 0; t < f->tamanho; t++) {
        printf("Chave: %c | Posicao: %d\n", f->item[i].chave,t);
        i = (i+1) % MAXTAM;
    }
}

//remove um item qualquer da fila
void desenfileira(Fila *f) {
    if (verificaFilaVazia(f)) {
        printf("Erro: a fila esta vazia.\n");
        return;
    }
    f->primeiro = (f->primeiro + 1) % MAXTAM;
    f->tamanho--;
}
//retorna 1 se a fila esta vazia ou 0 se nao está vazia
int verificaFilaVazia(Fila *f) {
    return f->tamanho == 0;
}

void liberaFila(Fila *f) {
    free(f);
}

int buscaChaveFila(Fila *f, char chave) {
    int i = f->primeiro;
    for (int t = 0; t < f->tamanho; t++) {
        if (chave == f->item[i].chave) {
            return 1;
        }
        i = (i+1) % MAXTAM;
    }
    return 0;
}

//Recebe uma fila por parâmetro, e retorna uma outra fila contendo apenas os elementos não duplicados
Fila *removeDuplicados(Fila *f) {
    Fila *f2 = criaFilaVazia();
    int i = f->primeiro;
    for (int t = 0; t < f->tamanho; t++) {
        if (buscaChaveFila(f2, f->item[i].chave) == 0) {//se nao existe na fila2, insere
            enfileira(f2, f->item[i].chave);
        }
        i = (i+1) % MAXTAM;
    }
    return f2;
}
char espia (Fila *f){
    if(verificaFilaVazia(f)){
        printf("Erro: Fila Vazia!\n");
        return;
    }
   return f->item[f->primeiro].chave;
}
char desenfileiraReturn(Fila *f){
    if(verificaFilaVazia(f)){
        printf("Erro: Fila vazia!\n");
        return;
    }
    char aux = f->item[f->primeiro].chave;
    f->primeiro = (f->primeiro + 1) % MAXTAM;
    f->tamanho--;
    return aux;
}
int enfileiraReturn(Fila * f, char chave){
    if(verificaFilaCheia(f)){
        printf("Erro: Fila Cheia!\n");
        return 0;
    }
    f->item[f->ultimo].chave = chave;
    f->ultimo = (f->ultimo + 1) % MAXTAM;
    f->tamanho++;
    return 1;
}
int buscaNaFila(Fila *f,char chave){
    int tam = f->tamanho;
    int i=f->primeiro;

    for(int t=0;t<tam;t++){
        if(f->item[i].chave==chave){
            return 1;
        }
        i = (i+1) % MAXTAM;
    }
    return 0;
}
Fila* retiraDuplicados(Fila *x){
    Fila *y = criaFilaVazia();
    int i= x->primeiro;
    int tam = x->tamanho;

    if(verificaFilaVazia(x)){
        printf("Erro: Fila Vazia!");
        return;
    }
    for(int t=0;t<tam;t++){
        if(!buscaNaFila(y,x->item[i].chave)){
            enfileira(y,x->item[i].chave);
        }
       i = (i+1) % MAXTAM;
    }
    return y;
}
/** ---------------------------------------------------------**/


typedef struct pilha {
    Item item[MAXTAM];
    int topo;
}Pilha;

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
void empilha(Pilha *p,char chave) {
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
        printf("Chave: %c | Posicao: %d\n", p->item[i].chave,i);
    }
}

//remove um item qualquer da pilha
char* desempilha(Pilha *p) {
    if (verificaPilhaVazia(p)) {
        printf("Erro: a pilha está vazia.\n");
        return;
    }
    p->topo--;
    return p->item[p->topo+1].chave;
}

//retorna 1 se a Pilha está vazia ou 0 se não está vazia
int verificaPilhaVazia(Pilha *p) {
    return p->topo == -1;
}

Fila* inverteFila (Fila *x){
    Pilha *p = criaPilhaVazia();
    Fila *y = criaFilaVazia();
    int tam = x->tamanho;
    int i = x->primeiro;

    for(int t=0;t<tam;t++){
        empilha(p,x->item[i].chave);
        i=(i+1)% MAXTAM;
    }
    tam = p->topo +1;
    for(int j=0;j<tam;j++){
        enfileira(y,desempilha(p));
    }
    free(p);
    return y;
}
int main (void){
    Fila *f = criaFilaVazia();

    enfileira(f,'B');
    enfileira(f,'o');
    enfileira(f,'A');
    enfileira(f,'!');
    printf("\n--- Fila X ---\n");
    imprimeFila(f);
    printf("\n--- Fila Y ---\n");
    f = inverteFila(f);
    imprimeFila(f);

    free(f);
}

