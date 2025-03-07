#include <stdio.h>


void printIdade(int *pIdade){
    printf("Voce tem %d anos", *pIdade);
}

int main(){

    int idade = 20;
    int *pIdade = NULL;
    pIdade = &idade;

    //printf("endereco da idade: %p\n", &idade);
    //printf("Valor de pIdade:   %p\n", pIdade);

    //printf("Valor da idade: %d\n", idade);
    //printf("Valor apontado por pIdade: %d\n", *pIdade);

    //printf("tamanho de idade: %d bytes\n", sizeof(idade));
    //printf("tamanho de pIdade: %d bytes\n", sizeof(pIdade));
    
    printIdade(pIdade);

    return 0;
}