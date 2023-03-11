/*Escreva um programa que leia uma string e dois valores numéricos a e b, chame uma
função que copie para uma segunda string as letras colocadas entre os índices a e b (inclusive)
na primeira string. A segunda string deve ser criada de forma dinâmica e ter o tamanho exato
para conter a string com os caracteres que receberá. Se um ou os dois índices forem
inadequados para a string lida (muito grandes, por exemplo), esta deve ser copiada inteira.*/
#include <stdio.h>
#include <stdlib.h>
char *funcao(char *v, int a, int b){
    int i,s=0;
    char *p;
    p = (char *) malloc (sizeof(char) * (b-a+2));
    for(i=a; i<=b; i++){
        *(p+s)=v[i];
        s++;
    }
    *(p+s)='\0';
    return p;
}
void main()
{
    char v[20], *p;
    int a,b, aux;
    printf("informe uma string: ");
    gets(v);
    printf("\nInforme dois numeros inteiros: ");
    scanf("%d",&a);
    scanf("%d",&b);
    if(a > b){
        aux = b;
        b=a;
        a=aux;
    }
    //printf("a = %d | b = %d", a, b);
    p= funcao(v, a,b);
    printf("%s", p);
    free(p);
}
