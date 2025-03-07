#include <stdio.h>

void ordena(int vetor[], int tamanho){

    for(int i = 0; i < tamanho -1; i++)
    {
        for(int j = 0; j < tamanho - i -1; j++)
        {
            if (vetor[j] < vetor[j+1])
            {
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
            
        }
    }
}

void pritnArray(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    
}

int main(){
    int vetor[10];
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    printf("Escolha 10 valores para o vetor:\n");
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }
    

    ordena(vetor, tamanho);
    pritnArray(vetor, tamanho);

    return 0;
}