/*Leia um vetor de 100 números reais (ponto flutuante). A partir deste vetor, crie outros dois,
um para conter os números maiores ou iguais à média, e outro para os números menores que
a média dos valores do vetor original. Estes dois vetores devem ser alocados dinamicamente e
ter o menor tamanho possível.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10
void funcao(float media, float v[], int t, int t2){
    float *p, *p2;
    int i, s1=0, s2=0;
    p = (float *) malloc (sizeof(float) * t);
    p2 = (float *) malloc (sizeof(float) * t2);
    for (i = 0; i < TAM; i++){
        if (v[i] >= media){
            *(p+s1) = v[i];
            s1++;
    }
        else{
            *(p2+s2) = v[i];
            s2++;
        }
    }
    printf("\nmaior ou igual:\n");
    for(i=0; i<s1; i++)
      printf("|%.2f|",p[i]);
    printf("\nmenor\n");
    for(i=0; i<s2; i++)
      printf("|%.2f|",p2[i]);
    free(p);
    free(p2);
}
void main()
{
    float v[TAM], media, soma=0;
    int i, s1=0, s2=0;
    printf("Informe os numeros:\n");
    for(i=0; i<TAM; i++){
        scanf("%f", &v[i]);
        soma = soma+v[i];
    }
    media = soma/TAM;
    printf("%.2f \n\n", media);
    for(i=0; i<TAM; i++){
        if (v[i]>= media){
            s1++;
        }
        else{
            s2++;
        }
    }
    printf("%d | %d \n\n", s1, s2);
    funcao(media, v, s1, s2);
}
