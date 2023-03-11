/*Fun��o para inserir na posi��o anterior do ponteiro base (in�cio e final) e retorna-l�*/
/*Fun��o para mostrar lista encadeada circular*/
/*Fun��o para remover lista encadeada circular*/

/******************************************************************************************************
 *1-Escreva uma fun��o que receba como par�metro uma lista encadeada circular e elimine todos os      *
 *elementos que estejam repetidos, mantendo apenas a primeira ocorr�ncia de cada, ou seja, de todos os*
 *elementos que possu�rem o mesmo conte�do, deve ficar apenas o primeiro.                             *
 ******************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct elemento {
    int valor;
    struct elemento *prox;
};
/*****************************************************************************************
 *INSERIR ELEMENTO NA POSI��O ANTERIOR DO MEU PONTEIRO BASE (IN�CIO E FINAL) E RETORNA-L�*
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
 *FUN��O PARA MOSTRAR LISTA ENCADEADA CIRCULAR*
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
 *FUN��O PARA REMOVER LISTA ENCADEADA CIRCULAR*
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
 *FUN��O PARA ELIMINAR REPETIDOS, MANTER SOMENTO O PRIMEIRO ELEMENTO DE CADA*
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
