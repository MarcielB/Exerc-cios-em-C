#include <stdio.h>
#include <stdlib.h>
int verificapalindromo(char *p, int tam, int aux){
    if(tam <= aux){
        return 1;
    }
    else{
        if(p[tam] != p[aux]){
            return 0;
        }
        else{
            return verificapalindromo(p, tam-1, aux+1);
        }
    }
}
int main()
{
    char palavra[20], *p;
    int tam, pali;
    printf("Informe uma palavra\n");
    gets(palavra);

    p = palavra;
    for(tam=0;*p;tam++, p++);
    printf("tamanho = %d\n", tam);

    pali = verificapalindromo(palavra, tam-1, 0);
    if (pali == 1)
    {
        puts("Eh um palindromo");
    }
    else{
        puts("Nao eh um palindromo");
    }

    return 0;
}
