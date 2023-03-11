/*Escreva um programa que leia uma string e passe esta string para uma função na qual
são trocadas de lugar a primeira e a última letras. A função deve receber a string através
de um ponteiro, e fazer a manipulação sem usar índices. Exiba a string original e a string
resultante através de um printf na função main. */
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
