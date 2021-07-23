#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM  3

typedef struct reservas Item;
typedef struct lista Lista;

struct reservas{
    int chave;
    char identificacao[40];
    float custo;;

};
struct lista{
    Item item[MAXTAM];
    int ultimo;
};
Lista* criaListaVazia (){
    Lista *l = malloc(sizeof(Lista));
    l->ultimo = -1;

    return l;
}
int verificaListaCheia(Lista* l){
    return l->ultimo == MAXTAM -1;
}
int verificaListaVazia (Lista* l){
    return l->ultimo == -1;
}
void adiciona_item_fim_da_lista(Lista *l,int chave,char identidicacao[], float custo){
    if(verificaListaCheia(l)){
        printf("\nErro: A lista esta cheia!");
        return;
    }

    Item novo_item;
    novo_item.chave = chave;
    novo_item.custo = custo;
    strcpy(novo_item.identificacao,identidicacao);
    //novo_item.identificacao = identidicacao;

    l->ultimo++;
    l->item[l->ultimo] = novo_item;
}
void imprimeLista(Lista *l){
    int tam = l->ultimo + 1;
    int i;
    for(i=0;i<tam;i++){
        printf("Identificacao da reserva: %d\n",l->item[i].chave,i);
        printf("Identificacao do hospede e do quarto: %s\n",l->item[i].identificacao);
        printf("Custo da diaria: %.2f\n",l->item[i].custo);
    }
    printf("\n");
}
int busca_item_por_chave(Lista *l,int chave){
    int i=0;

    while(i <= l->ultimo && l->item[i].chave!=chave){
        i++;
    }

    if(i <= l->ultimo)
        return i;

    else
        return -1;
}
void remove_item(Lista *l,int chave){
    int posicao,i,tam;
    posicao = busca_item_por_chave(l,chave);
    if(posicao==-1){
        printf("Erro: A lista esta vazia ou o item não existe!");
        return;
    }
    tam = l->ultimo + 1;
    for(i=posicao;i<tam-1;i++)
        l->item[i] = l->item[i+1];
    l->ultimo--;
}

void freeLista (Lista *l){
    free(l);
}
Lista* aumentoValor (Lista *l){
    if(verificaListaVazia(l)){
        printf("Erro: Lista Vazia!");
        return;
    }
    Lista * aux = criaListaVazia();

    for(int i=0;i<=l->ultimo;i++){
        float custo =  l->item[i].custo * 1.10;
        aux->ultimo++;
        aux->item[i].custo = custo;
        aux->item[i].chave = l->item[i].chave;
        strcpy(aux->item[i].identificacao,l->item[i].identificacao);
    }
    return aux;
}
int main(void){

    Lista *l = criaListaVazia();
    printf("Lista Vazia: %d\n\n",verificaListaVazia(l));
    adiciona_item_fim_da_lista(l,1,"Lucas",100.50);
    adiciona_item_fim_da_lista(l,2,"Funcio",110.50);
    adiciona_item_fim_da_lista(l,3,"Nereniudas",130.50);

    imprimeLista(l);
    printf("Lista cheia: %d\n\n",verificaListaCheia(l));

    l = aumentoValor(l);
    imprimeLista(l);

    remove_item(l,1);
    imprimeLista(l);

    freeLista(l);
}
