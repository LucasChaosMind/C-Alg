#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXTAM 3

typedef struct pedagio Item;
typedef struct pilha Pilha;


struct pedagio{
    int km;
    float valor;
    float custoKm;
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
void empilha(Pilha *p,int km,float valor, float custoKm) {
    if (verificaPilhaCheia(p)) {
        printf("Erro: a pilha esta cheia.\n");
        return;
    }

    Item novoItem;
    novoItem.km = km;
    novoItem.valor = valor;
    novoItem.custoKm = custoKm;
    p->topo++;
    p->item[p->topo] = novoItem;
}

//imprime a pilha
void imprimePilha(Pilha *p) {
    int tam = p->topo + 1;
    int i;
    for (i = 0; i < tam; i++) {
        printf("Km do trajeto: %d\n", p->item[i].km);
        printf("Valor do pedagio: %.2f\n",p->item[i].valor);
        printf("Custo por Km percorido: %.2f\n",p->item[i].custoKm);
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
void addPilha (Pilha *p){
    int km;
    float valor, custoKm;
    char c='s';

    while(p->topo<MAXTAM-1&&(c=='s'||c=='S')){
        printf("Informe a distancia: ");
        scanf("%d",&km);
        printf("Informe o Valor do pedagio: ");
        scanf("%f",&valor);
        printf("Informe o Custo por Km: ");
        scanf("%f",&custoKm);
        empilha(p,km,valor,custoKm);
        if(p->topo<MAXTAM-1){
            printf("Deseja continuar: S-N? ");
            scanf(" %c",&c);
        }
    }
}
void custoTotal(Pilha *p){
    float custoTotal,custoKm,valor;
    int km;
    if(verificaPilhaVazia(p)){
        printf("Erro: Pilha vazia!");
        return;
    }
    for(int i=0;i<=p->topo;i++){
        custoKm = p->item[i].custoKm;
        valor = p->item[i].valor;
        km = p->item[i].km;
        custoTotal += ((custoKm*(float)km) + valor);
    }
    printf("\nCusto Total da viagem: %.2f\n",custoTotal);
}
int main (void){

    Pilha *p = criaPilhaVazia();
    empilha(p,100,20,2.5);
    imprimePilha(p);
    desempilha(p);
    printf("\nInforme Sobre a viagem:\n");
    addPilha(p);
    printf("\n\n---Imprimindo Pilha ---\n");
    imprimePilha(p);
    printf("\n--- Custo Total ---\n");
    custoTotal(p);

}
