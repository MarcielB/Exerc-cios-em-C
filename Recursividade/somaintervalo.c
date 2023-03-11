/*********************************************************************************
 *Escrever um programa com uma função RECURSIVA que retorna a soma dos números   *
 *inteiros que existem entre n1 e n2 (inclusive ambos, mas sem repetir se n1=n2).*
 *Ler n1 e n2 antes da primeira chamada. Ex:                                     *
 *n=somaintervalo(3, 6); n recebe 18 (3 + 4 + 5 + 6)                             *
 *n=somaintervalo(5, 5); n recebe 5                                              *
 *n=somaintervalo(-2,3); n recebe 3 (-2 + -1 + 0 + 1 + 2 + 3)                    *
 *n=somaintervalo(4, 0); n recebe 10 (4 + 3 + 2 + 1 + 0)                         *
 *********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int somaintervalo(int n, int m){
    if (n <= m) {
        return n + somaintervalo(n + 1, m);
    }
    // no momento em que a n>m cai fora da chamada recursiva e retorna 0.
    return 0;
}
int main()
{
    int m, n, aux;
    printf("Informe os intervalos a serem somados: \n");
    scanf("%d %d", &n, &m);
    if(n > m){
        aux = m;
        m = n;
        n = aux;
    }
    printf("A soma entre %d e %d eh: %d", n, m, somaintervalo(n,m));
    return 0;
}
