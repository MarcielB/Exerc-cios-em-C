#include <stdio.h>
#include <stdlib.h>
struct elemento{
    int valor;
    struct elemento *fesq, *fdir;
};

struct elemento *inserir (int valor, struct elemento *arv) {
  struct elemento *novo, *ini;
  novo = (struct elemento *) malloc (sizeof(struct elemento));
  novo->valor = valor;
  novo->fdir = novo->fesq = NULL;
  if (!arv)
    return novo;
  ini = arv;
  while(arv != novo) {
    if (valor < arv->valor) {
      if (!arv->fesq)
        arv->fesq = novo;
      arv = arv->fesq;
      }
    else {
      if (!arv->fdir)
        arv->fdir = novo;
      arv = arv->fdir;
      }
    }
  return ini;
  }

  void eliminar(struct elemento *arv) {
  if (!arv)
    return;
  eliminar(arv->fesq);
  eliminar(arv->fdir);
  free(arv);
  }
struct elemento *localizar(int valor, struct elemento *arv){
    if(!arv)
        return NULL;

    if (valor == arv->valor){
        return arv;
    }
    else if(valor < arv->valor){
        return localizar(valor, arv->fesq);
    }
    else{
        return localizar(valor, arv->fdir);
    }
};

void mostrar(int nivel, struct elemento *arv) {
  int i;
  if (arv) {
    mostrar(nivel+1, arv->fdir);
    for(i = 0; i < nivel; i++)
      printf("   ");
    printf("%d\n", arv->valor);
    mostrar(nivel+1, arv->fesq);
    }
  else{
    for(i = 0; i < nivel; i++)
      printf("   ");
    printf("-\n");
    }
  }
/*Função que calcula a altura da arvore*/
int altura(struct elemento *arv){
    int esquerda, direita;
    if(!arv)
        return -1;

    esquerda = altura(arv->fesq);
    direita = altura(arv->fdir);
        if(esquerda > direita)
            return esquerda + 1;
        else
            return direita + 1;
}
/*Função que conta a quantidade de nós*/
int quantidade_de_nos(struct elemento *arv){
    //int soma;
    if(!arv)
        return 0;
    else
        return 1 + quantidade_de_nos(arv->fesq) + quantidade_de_nos(arv->fdir);
}
/*função que recebe como parâmetro uma árvore binária e retorna um valor inteiro que é a soma dos
campos valor dos nós da árvore que são nós folha.*/
int quantidade_de_folhas(struct elemento *arv){
    if(!arv)
        return 0;
    else if(!arv->fdir && !arv->fesq)
        return 1;
    else
        return quantidade_de_folhas(arv->fdir) + quantidade_de_folhas(arv->fesq);
}
/*Função que conta quantos nós existem em um determinado grau da arvore*/
int nos_grau_igual(struct elemento *arv, int grau){
    int s = 0;

    if(!arv)
        return 0;

    s += nos_grau_igual(arv->fesq, grau);
    s += nos_grau_igual(arv->fdir, grau);

    if(!arv->fesq && !arv->fdir && grau == 0)
        return s+1;
    if(((arv->fesq && !arv->fdir) || (!arv->fesq && arv->fdir)) && grau == 1)
        return s+1;
    if(arv->fesq && arv->fdir && grau == 2)
        return s+1;

    return s;
}
/*função que recebe como parâmetro um ponteiro para a raiz de uma árvore binária e um valor inteiro
indicando um nível, e retorna o número de nós deste nível na árvore.*/

int conta_nos_nivel(struct elemento *arv, int nivel){
    int n = 0;

    if(!arv)
        return 0;

    n += conta_nos_nivel(arv->fesq, nivel-1);
    n += conta_nos_nivel(arv->fdir, nivel-1);

    if(nivel == 0)
        return 1;

    return n;
}
/*Funão para somar todos os nós folhas*/
int somafolhas(struct elemento *arv){
    int s = 0;

    if(!arv)
        return 0;

    s += somafolhas(arv->fesq);
    s += somafolhas(arv->fdir);
    if(!arv->fesq && !arv->fdir)
        return arv->valor;

    return s;
}

struct elemento *menorv(struct elemento *arv){
    struct elemento *aux;

    if(!arv)
        return NULL;

    aux = menorv(arv->fesq);
    aux = menorv(arv->fdir);

    if(arv->fesq && arv->fdir){
        if(arv->valor < arv->fesq->valor && arv->valor < arv->fdir->valor /*&& arv->valor < aux->valor*/)
            return arv;
        if(arv->fesq->valor < arv->valor && arv->fesq->valor < arv->fdir->valor /*&& arv->valor < aux->valor*/)
            return arv->fesq;
        if(arv->fdir->valor < arv->valor && arv->fdir->valor < arv->fesq->valor && arv->valor < aux->valor)
            return arv->fdir;
    }

    if(arv->fesq){
        if(arv->valor < arv->fesq->valor)
            return arv;
        if(arv->fesq->valor < arv->valor)
            return arv->fesq;
    }

    if(arv->fdir){
        if(arv->valor < arv->fdir->valor)
            return arv;
        if(arv->fdir->valor < arv->valor)
            return arv->fdir;
    }
    printf("\n--%d--\n", arv->valor);
    return arv;

}
/*Função para achar maior e menor valor de uma arvore binaria*/
int menor_e_maior_valor(struct elemento *arv){
    struct elemento *aux;
    int nivel;
    aux = arv;

    for(nivel = 0; arv; arv = arv->fesq, nivel++);
    for( ; aux; aux = aux->fdir, nivel--);

    if(nivel == 0)
        return 0;
    else
        return 1;
}

/*Escreva uma função que receba como parâmetros um ponteiro apontando para a raiz de uma árvore binária de
pesquisa e um valor numérico, e retorne o valor da soma de todos os nós do caminho entre a raiz e o nó que
armazena o valor passado (inclusive). Se o valor não existir na árvore, deve ser retornado 0.*/

int soma_caminho(struct elemento *arv, int valor){
    int s = 0, f = 1;
    if(!arv)
        return 0;

    while(arv){
        if(valor == arv->valor)
            f = 0;
        if(valor < arv->valor){
            s += arv->valor;
            arv = arv->fesq;
        }
        else{
            s += arv->valor;
            arv = arv->fdir;
        }
    }
    if(f == 1)
        return 0;
    else
        return s;
}
///Função para achar menor elemento de arvore binaria de pesquisa///

struct elemento *menor_elemento(struct elemento *arv){

    if(!arv)
        return NULL;

    while(arv->fesq || arv->fdir){
        if(arv->fesq)
            arv = arv->fesq;
        else
            arv = arv->fdir;
    }
    return arv;
}

/*Construa uma função em C que receba como parâmetro um ponteiro apontando para a raiz de uma árvore
 binária e retorne 1 se todo nó não folha tem valor maior que seu(s) filho(s), e 0 caso contrário.*/

 int paiMfilho(struct elemento *arv){

    int f = 1;

    if(!arv)
        return 1;

    f = paiMfilho(arv->fesq);
    if(f == 0)
        return 0;
    f = paiMfilho(arv->fdir);
    if(f == 0)
        return 0;

    if(!arv->fesq && !arv->fdir)
        return 1;
    if((arv->fesq && arv->valor > arv->fesq->valor) && (arv->fdir && arv->valor > arv->fdir->valor))
        return 1;
    if((!arv->fesq && arv->valor > arv->fdir->valor) || (!arv->fdir && arv->valor > arv->fesq->valor))
        return 1;

    return 0;
}

/*Escreva uma função que receba como parâmetro um ponteiro para a raiz de uma árvore binária e retorne o
número de nós que têm valor menor que seu próprio nível*/
int nosmnivel_R(struct elemento *arv){
    int s = 0;

    if(!arv)
        return s;

    s += nosmnivel_R(arv->fesq);
    s += nosmnivel_R(arv->fdir);

    if((arv->valor > arv->fdir->valor)&&(arv->valor < arv->fesq->valor))
        return s+1;

    return s;
}

/*Escreva uma função que receba como parâmetro um ponteiro para a raiz de uma árvore binária (não
necessariamente de pesquisa) e retorne o nível do nó folha que é atingido por um caminho no qual o sucessor do nó
corrente é sempre o nó de menor valor dentre os nós filhos de corrente*/

int menor_caminho(struct elemento *arv){
    int nivel = 0;
    if (!arv)
        return -1;
    while(arv->fesq || arv->fdir) {
        if (!arv->fdir)
            arv=arv->fesq;
        else if (!arv->fesq)
            arv=arv->fdir;
        else if (arv->fesq->valor < arv->fdir->valor)
            arv=arv->fesq;
        else
            arv=arv->fdir;
        nivel++;
    }
  return nivel;
}
/*Escreva uma função que receba como parâmetros um valor inteiro X e um ponteiro apontando para a raiz de uma
árvore binária de pesquisa e retorne -1 se o valor X não existe na árvore, retorne 1 se o valor existe e está em nó folha, e
retorne 0 se o valor existe e está em nó que não é folha.
*/
int Verefica_se_existe_valor(struct elemento *arv, int valor){
    if (!arv)
        return -1;

    if((arv->valor == valor)&&(arv->fdir)&&(arv->fesq))
        return 0;
    if((arv->valor == valor)&&(!arv->fdir)&&(!arv->fesq))
        return 1;
    while(arv->fdir || arv->fesq){
        if (valor < arv->valor)
            arv=arv->fesq;
        if (valor > arv->valor)
            arv=arv->fdir;
        if ((arv->valor == valor) && (arv->fesq && arv->fdir))
            return 0;
        else if((arv->valor == valor) && (!arv->fesq && !arv->fdir))
            return 1;
        }
    return -1;
}
int main(){
    struct elemento *raiz = NULL, *busca;
    int opcao, num;
    do{
    printf("\n\n");
    printf("Informe a opcao:\n");
    puts("0  - Sair");
    puts("1  - Inserir");
    puts("2  - Imprimir");
    puts("3  - Buscar");
    puts("4  - Altura da arvore");
    puts("5  - Quantidade de nos");
    puts("6  - Quantidade de folhas");
    puts("7  - Quantidade de nos com graus igual");
    puts("8  - Quantidade de nos com de mesmo nivel");
    puts("9  - Soma folhas");
    puts("10 - Achar menor elemento");
    puts("11 - Procura maior e menor valor está no mesmo nivel");
    puts("12 - Soma caminho");
    puts("13 - Menor elemento folha");
    puts("14 - Verificar se todo no nao folha tem valor maior que seu filho");
    puts("15 - Menor que nivel");
    puts("16 - Verifica se exite valor");
    printf("\n\n");
    scanf("%d", &opcao);
    switch(opcao){
    case 1:
        printf("Digite um valor para inserir na arvore:\n");
        scanf("%d", &num);
        raiz = inserir(num, raiz);
        printf("\n\n");
        break;
    case 2:
        printf("\n\n\n\n");
        mostrar(0, raiz);
        printf("\n\n\n\n");
        break;
    case 3:
        printf("\n\n");
        printf("Digite o Valor a ser buscado:\n\n");
        scanf("%d", &num);
        busca = localizar(num, raiz);
        if(busca){
            printf("\n\n");
            printf("O valor %d foi encontrado na arvore\n\n", busca->valor);
            printf("\n\n");
        }
        else{
            printf("\n\n");
            printf("O valor %d nao foi encontrado\n\n", num);
            printf("\n\n");
        }
        printf("\n\n");
        break;
    case 4:
        printf("\n\n");
        printf("A altura da arvore eh: %d", altura(raiz));
        printf("\n\n");
        break;
    case 5:
        printf("\n\n");
        printf("A quantidade de nos da arvore eh: %d", quantidade_de_nos(raiz));
        printf("\n\n");
    case 6:
        printf("\n\n");
        printf("A quantidade de folhas da arvore eh: %d", quantidade_de_folhas(raiz));
        printf("\n\n");
        break;
    case 7:
        printf("Informe a o grau a ser pesquisado entre 0, 1 e 2:\n");
        scanf("%d", &num);
        printf("A quantidade de nos com grau %d na arvore eh: %d", num, nos_grau_igual(raiz, num));
        printf("\n\n");
        break;
    case 8:
        printf("Informe o nivel a ser contado:\n");
        scanf("%d", &num);
        printf("A quantidade de nos de nivel %d na arvore eh: %d", num, conta_nos_nivel(raiz, num));
        printf("\n\n");
        break;
    case 9:
        printf("A soma das folhas da rvore eh: %d", somafolhas(raiz));
        printf("\n\n");
        break;
    case 10:
        printf("O menor elemento eh: %d", menorv(raiz)->valor);
        printf("\n\n");
        break;
    case 11:
        if(menor_e_maior_valor(raiz) == 0)
            puts("O maior e menor valor da arvore estao no mesmo nivel");
        else
            puts("O maior e menor valor da arvore NAO estao no mesmo nivel");
        break;
    case 12:
        puts("Informe o valor: ");
        scanf("%d", &num);
        printf("A soma do caminho ate %d eh: %d",num, soma_caminho(raiz, num));
        printf("\n\n");
        break;
    case 13:
        printf("O menor elemento folha eh: %d", menor_elemento(raiz)->valor);
        printf("\n\n");
        break;
    case 14:
        if (paiMfilho(raiz) == 1)
            puts("No nao folha tem valor maior que seu(s) filho(s)");
        else
            puts("No nao folha NAO tem valor maior que seu(s) filho(s)");
    case 15:
        printf("O numero de elementos de menor valor que o seu niveleg: %d", menor_caminho(raiz));
        printf("\n\n");
        break;
    case 16:
        puts("Informe o valor a ser buscado");
        scanf("%d", &num);
        if (Verefica_se_existe_valor(raiz, num) == 1)
            puts("Valor existe e esta em no folha");
        else if(Verefica_se_existe_valor(raiz, num) == 0)
            puts("Valor existe e nao esta em no folha");
        else
            puts("Valor nao existe");
    }
    }while(opcao !=0);

    eliminar(raiz);
    return 0;
}
