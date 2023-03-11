/*******************************************************************************************************
 *5. Escreva uma função para mesclar duas listas duplamente encadeadas, ordenadas de forma crescente,  *
 *recebidas como parâmetros, ou seja, transformar as duas em uma mantendo a ordenação. A mescla deve   *
 *ser feita percorrendo as duas listas, e não concatenando uma no fim da outra e então ordenando. Além *
 *disso, nenhum novo elemento deve ser alocado.                                                        *
 *******************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
struct elemento{
    int x;
    struct elemento *ant, *prox;
};

/***************************************
 *INSERIR NA LISTA DUPLAMENTE ENCADEADA*
 ***************************************/

struct elemento *inserir(int v, struct elemento *lista) {
    struct elemento *novo;
    novo = (struct elemento *) malloc (sizeof(struct elemento));
    novo->x = v;
    novo->ant = NULL;
    novo->prox = lista;
    if (lista) {
        for(; lista->ant; lista = lista->ant);
        lista->ant = novo;
    }
    return novo;
}
/************************************
 *MOSTRAR LISTA DUPLAMENTE ENCADEADA*
 ************************************/
void mostrar(struct elemento *lista) {
    if (lista)
    for(; lista->ant; lista = lista->ant);
    for (; lista; lista=lista->prox)
        printf("%d ", lista->x);
}

/********************************************
 *MOSTRAR LISTA DUPLAMENTE ENCADEADA INVERSA*
 ********************************************/
void mostrarInv(struct elemento *lista) {
    if (lista)
    for(; lista->prox; lista = lista->prox);
    for (; lista; lista=lista->ant)
        printf("%d ", lista->x);
}
/*************************************
 *ELIMINAR LISTA DUPLAMENTE ENCADEADA*
 *************************************/
void eliminar(struct elemento *lista) {
    struct elemento *aux, *ant;
    if (!lista)
        return;
    ant = lista->ant;
    while (lista) {
        aux = lista;
        lista=lista->prox;
        free(aux);
    }
    while (ant) {
        aux = ant;
        ant=ant->ant;
        free(aux);
    }
}
/****************************************************
 *INSERIR ORDENADA EM UMA LISTA DUPLAMENTE ENCADEADA*
 ****************************************************/
struct elemento *inserirOrdenado(int valor, struct elemento *lista) {
    struct elemento *novo;
    novo = (struct elemento *) malloc (sizeof(struct elemento));
    novo->x = valor;
    if (!lista) {
        novo->ant = NULL;
        novo->prox = NULL;
        return novo;
    }
    if (valor > lista->x){
        for ( ; lista->prox && lista->prox->x < valor; lista=lista->prox);
        novo->prox = lista->prox;
        novo->ant = lista;
        lista->prox = novo;
        if (novo->prox)
            novo->prox->ant = novo;
    }
    else {
        for ( ; lista->ant && lista->ant->x > valor; lista=lista->ant);
        novo->ant = lista->ant;
        novo->prox = lista;
        lista->ant = novo;
        if (novo->ant)
            novo->ant->prox = novo;
    }
    return novo;
}

/*****************************************************
 * MESCLAR DUAS LISTAS DUPLAMENTE ENCADEADA CRESCENTE*
 *****************************************************/

void mesclar (struct elemento *lista1, struct elemento *lista2) {
    struct elemento *aux, *ini;
    if (!lista1)
        return;

    else if (!lista2)
        return;

    else {

        for(; lista1->ant; lista1 = lista1->ant);
        for(; lista2->ant; lista2 = lista2->ant);

        if(lista1->x >= lista2->x){
        ini = aux = lista2;
        lista2 = lista2->prox;
        aux->ant = NULL;
        }

        else {
        ini = aux = lista1;
        lista1 = lista1->prox;
        aux->ant = NULL;
        }
    while(lista1 && lista2) {
        if (lista1->x >= lista2->x) {
            aux->prox = lista2;
            lista2 = lista2->prox;
            aux->prox->ant = aux;
            aux = aux->prox;
        }
        else{
            aux->prox = lista1;
            lista1 = lista1->prox;
            aux->prox->ant = aux;
            aux = aux->prox;
        }
    }

    if (!lista1){
        aux->prox = lista2;
        lista2->ant= aux;
    }
    else{
        aux->prox = lista1;
        lista1->ant = aux;
    }
    }
  }

int main() {
    struct elemento *lista1, *lista2, *mescla;
    int n;
    lista1 = NULL;
    lista2 = NULL;
    mescla = NULL;
    puts("Informe um número ou -0 para sair: ");
    scanf("%d", &n);
    while(n != -0){
        lista1 = inserirOrdenado(n, lista1);
        puts("Informe um número ou -0 para sair: ");
        scanf("%d", &n);
    }
    puts("Informe um número ou -0 para sair: ");
    scanf("%d", &n);
    while(n != -0){
        lista2 = inserirOrdenado(n, lista2);
        puts("Informe um número ou -0 para sair: ");
        scanf("%d", &n);
    }
    puts("Lista 1:");
    mostrar(lista1);
    printf("\n");
    puts("Lista 2:");
    mostrar(lista2);
    printf("\n");
    mesclar(lista1, lista2);
    mostrar(lista1);
//  printf("\n");
//  lista = eliminarRepetidosFicaPenultimo(lista);

  eliminar(lista1);
  return 0;
  }
