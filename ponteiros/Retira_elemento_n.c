/*. Escreva um programa que leia um valor inteiro n e um vetor de 400 elementos inteiros. A seguir, passe
os dados lidos para uma função em que o elemento da posição n é retirado, todos elementos da sua direita
(de endereços maiores) deslocados uma posição para a esquerda, e o elemento originalmente na posição n
recolocado no final do vetor. Como exemplo, imagine um vetor de 5 elementos como o da figura:
2 8 4 5 9
Lido o valor 2 para n, o vetor resultante deve ser
2 8 5 9 4
A função deve receber o vetor através de um ponteiro para o primeiro elemento, e não devem ser usados
índices na manipulação.*/
#include <stdio.h>
#include <stdlib.h>
#define NUM 5
void elementosai(int n, int *vet, int *p){
    int aux;
    aux = *(vet+n);
    //printf("%d\n", aux);
    for( ;vet < p-1; vet++){
            //printf("%d, %d\n\n", &*vet+1, &*p);
        if(*vet == aux){
            *vet = *(vet+1);
            *(vet+1) = aux;            // 10//20//40//50//60//\0
        }
    }
    *(vet) = aux;
}

main(){
    int n,i, vet[NUM];

    printf("Digite o valor de n: ");
    scanf("%d", &n);
    printf("Digite os valores para para o vetor: ");
    for(i = 0; i < NUM; i++){
        scanf("%d", &vet[i]);
    }
    elementosai(n,vet, &vet[i]);
    printf("Resultado final do vetor: ");
    for(i = 0; i < NUM; i++){
        printf("|%d", vet[i]);
    }

}
