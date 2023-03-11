/************************************************************************************************
 *3. Construa uma função que receba como parâmetros dois ponteiros que apontam para elementos de*
 *uma lista circular com encadeamento simples. A função deve trocar de posição os dois elementos*
 ************************************************************************************************/

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
/***************************************
 *FUNÇÃO PARA TROCAR ELEMENTOS DE LUGAR*
 ***************************************/
/*void InvElem(struct elemento *lista, int n, int m){
    struct elemento *aux1, *aux2, aux3;
    int i, j;
    if(!lista)
        return;
    if(lista->prox == lista)
        return;

    //for(aux1=lista; aux1->prox!= ini &&  n > 2; n--, aux1 = aux1->prox);
    //for(aux2=lista; aux2->prox!= ini &&  m > 2; m--, aux2 = aux2->prox);
    for(aux1=lista; aux1->prox!= lista &&  aux1->prox->valor != n; aux1 = aux1->prox);
    for(aux2=lista; aux2->prox!= lista &&  aux2->prox->valor != m; aux2 = aux2->prox);
    printf("%d e i = %d", aux1->valor, i);
    printf("%d e j = %d", aux2->valor, j);
    aux1->prox = lista;
    aux2->prox = lista2;
    aux3 = lista->prox;
    lista->prox= lista2->prox;
    lista2->prox= aux3;
}
*/
/***************************************
 *FUNÇÃO PARA TROCAR ELEMENTOS DE LUGAR*
 ***************************************/
struct elemento *troca_de_posicao(struct elemento *lista, struct elemento *lista2){
    struct elemento *aux, *aux2, *aux3;
    aux3 = (struct elemento *)malloc(sizeof(struct elemento));

    if(!lista || !lista2 || lista == lista2)
        return lista;

    for(aux = lista; aux->prox != lista2; aux = aux->prox);
    for(aux2 = lista2; aux2->prox != lista; aux2 = aux2->prox);

    aux->prox = lista;
    aux2->prox = lista2;
    aux3 = lista->prox;
    lista->prox= lista2->prox;
    lista2->prox= aux3;

    return lista2;
}

int main(){
    struct elemento *lista, *lista2;
    int n;
    lista = NULL;

    puts("Digite um valor para inserirR na lista ou -1 para sair");
    scanf("%d", &n);
    while(n != -1){
        lista = insertcircini(lista, n);
        puts("Digite outro valor para inserir na lista ou -1 para sair");
        scanf("%d", &n);
    }

    lista2 = lista->prox->prox->prox;

    printf("%d", lista2->valor);
    mostrar(lista);
    lista = troca_de_posicao(lista, lista2);
    mostrar(lista);
    Elimlist(lista);


return 0;
}
