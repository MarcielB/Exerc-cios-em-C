/*Escreva um programa que leia um vetor de 50 elementos inteiros em ordem crescente e passe este vetor
para uma fun��o que verifica se � constante a diferen�a existente entre cada elemento e seu sucessor no
vetor. Na fun��o main, exiba a diferen�a, se esta for constante, ou uma mensagem informando que n�o h�
diferen�a constante. A fun��o deve receber o vetor atrav�s de um ponteiro para o primeiro elemento, e n�o
devem ser usados �ndices na manipula��o.
Exemplo: na sequencia 2 4 6 8 10, a diferen�a entre os elementos � constante; j� em 2 4 5 7 10, a diferen�a
n�o � constante.*/
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
