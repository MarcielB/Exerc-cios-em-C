/*Escreva um programa que leia duas strings, S1 e S2, que devem ser passadas como argumentos para
uma função. Na função, uma nova string deve ser criada a partir da composição das duas recebidas como
parâmetro. Para essa composição, a string S2 deve ser inserida na string S1 substituindo a primeira
ocorrência (em S1) de letra igual à primeira letra de S2. Por exemplo, considere as strings
“motor”
 “oni”
caso em que o resultado deve ser
“monitor”.
Se a primeira letra de S2 não ocorrer em S1, S2 deve ser simplesmente concatenada ao final de S1. A
string que receberá o resultado deve ser alocada de forma a ter tamanho exato para o seu conteúdo.*/
#include <stdio.h>
#include <stdlib.h>
char *juncao(char *s1, char *s2) {
    char *p, *res;
    int tam, temLetra = 0;
    for(p = s1; *p; p++) {
        if (*p == *s2)
            temLetra = 1;
    }
    tam = p - s1;
    for(p = s2; *p; p++);
    tam += p - s2;
//  res = (char *) malloc ((tam+(!temLetra)) * sizeof(char));
  if (temLetra) {
    res = (char *) malloc (tam * sizeof(char));
    for (p = res; *s1 != *s2; p++, s1++)
      *p = *s1;
    for (; *s2; p++, s2++)
      *p = *s2;
    for (s1++; *s1; p++, s1++)
      *p = *s1;
    }
  else {
    res = (char *) malloc ((tam+1) * sizeof(char));
    for (p = res; *s1; p++, s1++)
      *p = *s1;
    for (; *s2; p++, s2++)
      *p = *s2;
    }
  *p = '\0';
  return res;
  }
int main()
{
    char s1[20], s2[20], *R;
    puts("Informe duas strings");
    gets(s1);
    gets(s2);
    R=juncao(s1, s2);
    puts(R);
    return 0;
}
