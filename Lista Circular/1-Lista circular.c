/*Função para inserir na posição anterior do ponteiro base (início e final) e retorna-lô*/
/*Função para mostrar lista encadeada circular*/
/*Função para remover lista encadeada circular*/

/******************************************************************************************************
 *1-Escreva uma função que receba como parâmetro uma lista encadeada circular e elimine todos os      *
 *elementos que estejam repetidos, mantendo apenas a primeira ocorrência de cada, ou seja, de todos os*
 *elementos que possuírem o mesmo conteúdo, deve ficar apenas o primeiro.                             *
 ******************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct elemento {
    int valor;
    struct elemento *prox;
};
/*****************************************************************************************
 *INSERIR ELEMENTO NA POSIÇÃO ANTERIOR DO MEU PONTEIRO BASE (INÍCIO E FINAL) E RETORNA-LÔ*
 *****************************************************************************************/
struct elemento *insertcircini(struct elemento *ini, int n){
    struct elemento *aux, *paux;
    aux = (struct elemento *)malloc(sizeof(struct elemento));
    aux->valor=n;
    if(!ini){
        aux->prox = aux;
        return aux;
    }
    aux->prox=ini;
    for(paux = ini; paux->prox != ini; paux = paux->prox);
    paux->prox = aux;
    return aux;
}
/**********************************************
 *FUNÇÃO PARA MOSTRAR LISTA ENCADEADA CIRCULAR*
 **********************************************/
void mostrar(struct elemento *ini){
    struct elemento *aux;
    puts("\nLista encadeada circular");
    aux = ini;
    do{
        printf("%d  ", aux->valor);
        aux= aux->prox;
    }
    while(aux != ini);
}
/**********************************************
 *FUNÇÃO PARA REMOVER LISTA ENCADEADA CIRCULAR*
 **********************************************/
void Elimlist(struct elemento *ini){
    struct elemento *aux, *paux;
    aux = ini;
    do{
        paux = aux;
        aux = aux->prox;
        free(paux);
    }
    while(ini != aux);
}
/****************************************************************************
 *FUNÇÃO PARA ELIMINAR REPETIDOS, MANTER SOMENTO O PRIMEIRO ELEMENTO DE CADA*
 ****************************************************************************/
void Elimrep(struct elemento *lista){
    struct elemento *aux, *ini, *paux, *lx;
    int fl = 0;
    ini = lista;
    if(!lista)
        return;
    if(lista->prox == lista)
        return;
    do{
        for(aux = lista;aux->prox != ini; ) {
            if(aux->prox->valor == lista->valor) {
            paux = aux->prox;
            aux->prox = aux->prox->prox;
            free(paux);
            }
            else
            aux = aux->prox;
      }
    lista = lista->prox;
    }while(lista != ini);
}

int main(){

    int n;
    struct elemento *lista;
    lista=NULL;

     puts("Digite valores para inserir na lista ou -1 para sair");
    scanf("%d", &n);
    while(n != -1){
        lista = insertcircini(lista, n);
        puts("Digite valores para inserir na lista ou -1 para sair");
        scanf("%d", &n);
    }
    mostrar(lista);
    Elimrep(lista);
    mostrar(lista);
    Elimlist(lista);

return 0;
}
