/*Escreva um programa que leia uma string e passe esta string para uma fun��o na qual
s�o trocadas de lugar a primeira e a �ltima letras. A fun��o deve receber a string atrav�s
de um ponteiro, e fazer a manipula��o sem usar �ndices. Exiba a string original e a string
resultante atrav�s de um printf na fun��o main. */
#include <stdio.h>
#include <stdlib.h>
void troca(char *palavra){
    char aux, aux2, *p;
    int i=0;
    aux = *palavra;
    p=palavra;
    for(;*p;p++, i++);
    aux2 = *(p-2);
    *(palavra+0)=aux2;
    *(palavra+i-2)=aux;
    printf("letras: %c %c\n ", aux, aux2);
}
int main()
{
    char palavra[20];
    puts("Informe uma palavra:");
    fflush(stdin);
    fgets(palavra, 20, stdin);
    printf("String original: %s", palavra);
    troca(palavra);
    printf("String resultante: %s", palavra);
    return 0;
}
