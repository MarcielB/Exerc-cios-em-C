/* Escreva um programa que chame uma fun��o onde uma string recebe como conte�do as 26 letras do
alfabeto, em ordem. A string deve ser exibida na tela ap�s o retorno para a fun��o main, e apresentar o
conte�do �ABCDEFGHIJKLMNOPQRSTUVWXYZ�. A manipula��o na fun��o deve ser feita atrav�s de
ponteiros, sendo evitado o uso de �ndices, e a string deve ser mostrada ap�s o retorno para a fun��o main.
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
