#include <stdio.h>
#include <stdlib.h>

#define MAXTAM  6

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
void adiciona_item_fim_da_lista(Lista *l,int chave){
    if(verificaListaCheia(l)){
        printf("\nErro: A lista esta cheia!");
        return;
    }

    Item novo_item;
    novo_item.chave = chave;
    l->ultimo++;
    l->item[l->ultimo] = novo_item;
}
void imprimeLista(Lista *l){
    int tam = l->ultimo + 1;
    int i;
    for(i=0;i<tam;i++){
        printf("Identificacao da reserva: %d\n",l->item[i].chave,i);
        printf("Identificacao do hospede e do quarto: %s\n",l->item[i].identificacao);
        printf("Custo da diaria: %.2f",l->item[i].custo);
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
void addNaLista(Lista *l,int posicao,int chave){
    if(verificaListaCheia(l)){
        printf("Erro: Lista cheia ou possicao incoreta!\n");
        return;
    }
    if(posicao > l->ultimo +1){
        printf("Erro: Posiccao Invalida\n");
        return;
    }
    int elementos = l->ultimo + 1;
    l->ultimo++;
    for(int i = elementos ; i > posicao; i--){
        l->item[i] = l->item[i-1];
    }
    l->item[posicao].chave = chave;
    printf("Valor Inserido!\n");

}
void ordenaLista(Lista *l){
    int i,j;
    int tam = l->ultimo;

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            if(l->item[j].chave>l->item[j+1].chave){
                int aux = l->item[j].chave;
                l->item[j].chave = l->item[j+1].chave;
                l->item[j+1].chave = aux;
            }
        }
    }
}
void addValorOrdenado(Lista *l, int chave){
    int i=0;
    if(verificaListaCheia(l)){
        printf("Lista cheia!\n");
        return;
    }
    while((i<l->ultimo)&&(l->item[i].chave<chave)){
        i++;
    }
    return addNaLista(l,i,chave);
}
void libera_lista(Lista *l){
    free(l);
}
void copiaLista(Lista *x,Lista *y){
    int i=0;
    if(!verificaListaVazia(y)){
        printf("Lista de Destino!");
        return;
    }
    for(i=0;i<=x->ultimo;i++){
        y->ultimo++;
        y->item[i]=x->item[i];
    }
}
void freeLista (Lista *l){
    free(l);
}

Lista* inteccao(Lista *x,Lista *y){
    Lista *z = criaListaVazia();
    int i,j;
    int tamx = x->ultimo;
    int tamy = y->ultimo;
    for(i=0;i<tamx;i++){
        for(j=0;j<tamy;j++){
            if(x->item[i].chave == y->item[j].chave){
                z->ultimo++;
                z->item[z->ultimo]=x->item[i];
            }
        }
    }
    return z;
}
int main(void){

}
