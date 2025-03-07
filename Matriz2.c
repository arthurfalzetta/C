// Exemplo de matriz representada por vetor de ponteiros

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ORDEM 3



int main(int argc, char *argv[])
{
    srand(time(0));
    // declaração de variável ponteiro para ponteiro
    int **mat, **matrizB, **matrizC;
    // alocando o vetor de ponteiros
    mat = (int**)malloc(ORDEM * sizeof(int*));
    matrizB = (int**)malloc(ORDEM * sizeof(int*));
    matrizC = (int**)malloc(ORDEM * sizeof(int*));
    // alocando cada uma das linhas da matriz
    int i;
    for( i = 0; i < ORDEM; i++){
        mat[i] = (int*)malloc(ORDEM * sizeof(int));
        matrizB[i] = (int*)malloc(ORDEM * sizeof(int));
        matrizC[i] = (int*)malloc(ORDEM * sizeof(int));
    }
    int j;
    // preenchendo a matriz
    for(i = 0; i < ORDEM; i++)
    {
        for(j = 0; j < ORDEM; j++){
            mat[i][j] = i + j;
        }
    }

    for(i = 0; i < ORDEM; i++)
    {
        for(j = 0; j < ORDEM; j++){
            matrizB[i][j] = (rand() % 11);
        }
    }

    for (i = 0; i < ORDEM; i++) {
        for (j = 0; j < ORDEM; j++) {
            matrizC[i][j] = mat[i][j] + matrizB[i][j];
        }
    }

    // mostrando os elementos da matriz
    printf("\nMatriz A:\n");
    for(i = 0; i < ORDEM; i++)
    {
        for(j = 0; j < ORDEM; j++){
            printf("%d\t", mat[i][j]);
        } 
        printf("\n");
    }

    printf("\nMatriz B:\n");
    for(i = 0; i < ORDEM; i++)
    {
        for(j = 0; j < ORDEM; j++){
            printf("%d\t", matrizB[i][j]);
        } 
        printf("\n");
    }

    printf("\nMatriz C (A+B):\n");
    for(i = 0; i < ORDEM; i++)
    {
        for(j = 0; j < ORDEM; j++){
            printf("%d\t", matrizC[i][j]);
        } 
        printf("\n");
    }
    // liberando o espaço de memória
    // libera cada linha
    for(i = 0; i < ORDEM; i++){
        free(mat[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    // libera o vetor de ponteiros
    free(mat);
    free(matrizB);
    free(matrizC);
    return 0;
}