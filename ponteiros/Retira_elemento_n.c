/*. Escreva um programa que leia um valor inteiro n e um vetor de 400 elementos inteiros. A seguir, passe
os dados lidos para uma fun��o em que o elemento da posi��o n � retirado, todos elementos da sua direita
(de endere�os maiores) deslocados uma posi��o para a esquerda, e o elemento originalmente na posi��o n
recolocado no final do vetor. Como exemplo, imagine um vetor de 5 elementos como o da figura:
2 8 4 5 9
Lido o valor 2 para n, o vetor resultante deve ser
2 8 5 9 4
A fun��o deve receber o vetor atrav�s de um ponteiro para o primeiro elemento, e n�o devem ser usados
�ndices na manipula��o.*/
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
