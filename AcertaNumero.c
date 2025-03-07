#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int MIN = 1;
    const int MAX = 100;
    int escolha;
    int escolhas = 0;
    int resposta;

    srand(time(0));

    resposta = (rand() % MAX) + MIN;

    do
    {
        printf("Escolha: ");
        scanf("%d", &escolha);
        if (escolha > resposta)
        {
            printf("Muito alta\n");
        }
        else if (escolha < resposta)
        {
            printf("Muito baixa\n");
        }
        else{
            printf("CORRETO!\n");
        }
        escolhas++;
    } while (escolha != resposta);
    
    printf("-------------------------\n");
    printf("Resposta: %d\n", resposta);
    printf("Tentativas: %d\n", escolhas);
    printf("-------------------------");

    return 0;
}