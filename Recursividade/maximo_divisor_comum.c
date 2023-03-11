#include <stdio.h>
#include <stdlib.h>
/*Escreva um programa que leia dois números inteiros e chame uma função RECURSIVA
que receba os valores lidos como parâmetros e retorne o Máximo divisor comum entre
eles. Dados dois inteiros positivos, X e Y, seu máximo divisor comum D pode ser
encontrado segundo três casos distintos:
 (1) Se X e Y são iguais, então D é igual a X;
 (2) Se X<Y, então D é igual ao mdc entre X e a diferença Y-X;
 (3) Se X>Y, então D é igual ao mdc entre a diferença X-Y e Y. 
*/

int mdc(int x, int y){
    if(x==y){
        return x;
    }
    else if(x<y){
        return mdc(x, (y-x));
    }
    else{
        return mdc((x-y), y); 
    }
}
int main()
{
    int x, y;
    printf("Informe dois numeros:\n");
    scanf("%d %d", &x, &y);
    printf("O maximo divisor comum entre %d e %d eh: %d", x, y, mdc(x,y));
    return 0;
}
