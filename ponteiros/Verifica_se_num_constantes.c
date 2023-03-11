/*Escreva um programa que leia um vetor de 50 elementos inteiros em ordem crescente e passe este vetor
para uma função que verifica se é constante a diferença existente entre cada elemento e seu sucessor no
vetor. Na função main, exiba a diferença, se esta for constante, ou uma mensagem informando que não há
diferença constante. A função deve receber o vetor através de um ponteiro para o primeiro elemento, e não
devem ser usados índices na manipulação.
Exemplo: na sequencia 2 4 6 8 10, a diferença entre os elementos é constante; já em 2 4 5 7 10, a diferença
não é constante.*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int verifica(int *v, int *p){
    int c=1, dif;
    dif= *(v+1)- *v;
    for(;v<p;v++){
        if((*(v+1)- *v)== dif){
            c++;
            if(c == TAM)
                break;
        }
    }
    return c;
}
int main()
{
    int vet[TAM], n, i;
    printf("infome os %d elementos o vetor: \n", TAM);
    for (i=0;i<TAM;i++){
        scanf("%d", &vet[i]);
    }
    n = verifica(vet, &vet[i]);
    //printf("%d", n);
    if(n == TAM){
        puts("O vetor tem numeros constantes");}
    else{
        puts("O vetor nao tem numeros constantes");}
    return 0;
}
