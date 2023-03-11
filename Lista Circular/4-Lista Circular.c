/************************************************************************************************
 *4. Escreva uma função que receba como parâmetro duas listas encadeadas circulares, e retorne o*
 *número de elementos presentes na primeira que têm elementos com mesmo valor na segunda.       *
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
/****************************************
 *FUNÇÃO PARA VERIFICAR ELEMENTOS IGUAIS*
 ****************************************/
int ElemIguais(struct elemento *lista, struct elemento *lista2){
    struct elemento *ini, *ini2;
    int cont = 0;
    ini=lista;
    ini2=lista2;
    do{
        lista2 = ini2;
        if(lista2->valor == lista->valor){
            cont++;
        }
        else{
            lista2 = lista2->prox;
            for( ;lista->valor != lista2->valor && lista2 != ini2; lista2= lista2->prox);
            if(lista2->valor == lista->valor)
                cont++;
        }
        lista=lista->prox;
    }while(lista!= ini);

    return cont;
}
int main(){

    int n, e1;
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
    mostrar(lista2);
    printf("\n\n");
    e1 = ElemIguais(lista1, lista2);
    printf("Existem %d iguais", e1);
    Elimlist(lista1);
    Elimlist(lista2);

return 0;
}
