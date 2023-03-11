/***************************************************************************************************************
 *2-Escreva uma função que receba como parâmetros dois ponteiros, um para o primeiro elemento da primeira lista*
 *circular e outro para o primeiro elemento da segunda lista circular. O programa deve retornar 1 se as listas *
 *são iguais ou 0 caso contrário (iguais significa listas com mesmo tamanho, com mesmos valores na mesma ordem)*                             *
 ***************************************************************************************************************/

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
/***********************************************
 *FUNÇÃO PARA VERIFICAR SE AS LISTAS SÃO IGUAIS*
 ***********************************************/
int verificalistas(struct elemento *lista1, struct elemento *lista2){
    struct elemento *aux1, *aux2;
    if(!lista1 || !lista2)
        return;
    if(lista1->prox == lista1 || lista2->prox == lista2)
        return;

    for(aux1 = lista1->prox, aux2 = lista2->prox; lista1->valor == lista2->valor && aux1 != lista1 && aux2 != lista2; aux1 = aux1->prox, aux2=aux2->prox);
    if(aux1 == lista1 && aux2 == lista2 && lista1->valor == lista2 ->valor){
        return 1;
    }
    return 0;
}

int main(){

    int n, res;
    struct elemento *lista1, *lista2;
    lista1=NULL;
    lista2=NULL;
    puts("Digite valores para inserir na lista ou -1 para sair");
    scanf("%d", &n);
    while(n != -1){
        lista1 = insertcircini(lista1, n);
        fflush(stdin);
        puts("Digite valores para inserir na lista ou -1 para sair");
        scanf("%d", &n);
    }
    fflush(stdin);
    puts("Digite valores para inserir na lista ou -1 para sair");
    scanf("%d", &n);
    while(n != -1){
        lista2 = insertcircini(lista2, n);
        fflush(stdin);
        puts("Digite valores para inserir na lista ou -1 para sair");
        scanf("%d", &n);
    }
    mostrar(lista1);
    printf("\n\n");
    mostrar(lista2);
    printf("\n\n");
    res=verificalistas(lista1, lista2);

    if(res==1)
        printf("Listas Iguais resultado = %d\n", res);
    else
        printf("Listas diferentes resultado = %d\n", res);

    Elimlist(lista1);
    Elimlist(lista2);

return 0;
}
