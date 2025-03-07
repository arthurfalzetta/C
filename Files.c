#include <stdio.h>

int main(){

    FILE *pF = fopen("exercicio.txt", "w");
    fprintf(pF, "Exercicio da atividade 1 LAB");
    fprintf(pF, "\nTeste de fprint");


    fclose(pF);

    pF = fopen("exercicio.txt", "a");

    fprintf(pF, "\nLinha adicionada posteriormente");


    return 0;
}