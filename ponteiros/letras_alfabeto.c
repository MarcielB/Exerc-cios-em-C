/* Escreva um programa que chame uma função onde uma string recebe como conteúdo as 26 letras do
alfabeto, em ordem. A string deve ser exibida na tela após o retorno para a função main, e apresentar o
conteúdo “ABCDEFGHIJKLMNOPQRSTUVWXYZ”. A manipulação na função deve ser feita através de
ponteiros, sendo evitado o uso de índices, e a string deve ser mostrada após o retorno para a função main.
*/
#include <stdio.h>
#include <stdlib.h>
void  gera_alfabeto(char *p){
    int letra;
    for(letra='A'; letra <='Z'; letra++){
        *(p++)=letra;
    }
    *p='\0';
}
main()
{
    char alfabeto[27];
    gera_alfabeto(alfabeto);
    printf("alfabeto: %s", alfabeto);
}
