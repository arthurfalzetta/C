#include <stdio.h>
#include <ctype.h>

int main()
{
    char perguntas[][100] = {"1. 2 + 2? ",
                            "2. Qual o maior peixe do mundo? ",
                            "3. Quando o Brasil ganhou o penta da copa? " };
    char alterntivas[][100] = {"A. 3", "B. 4", "C. 5", "D. 6",
                                "A. Peixe pedra", "B. Tubarao branco", "C. Tubarao baleia", "D. Peixe lua",
                                "A. 2006", "B. 1998", "C. 2004", "D. 2002"};

    char resposta[3] = {'B', 'C', 'D'};
    int numeroDePerguntas = sizeof(perguntas)/sizeof(perguntas[0]);

    char escolha;
    int pontos = 0;

    printf("Quiz\n");

    for (int i = 0; i < numeroDePerguntas; i++)
    {
        printf("--------------------------\n");
        printf("%s\n", perguntas[i]);
        printf("--------------------------\n");

        for (int j = (i*4); j < (i*4)+4; j++)
        {
            printf("%s\n", alterntivas[j]);
        }

    
        printf("Responda: ");
        scanf(" %c", &escolha);

        escolha = toupper(escolha);

        if (escolha == resposta[i])
        {
            printf("Correto!\n");
            pontos++;
        }
        else
        {
            printf("Errado!\n");
        }
        
        
    }
    
    printf("--------------------------\n");
    printf("Pontos finais: %d/%d\n", pontos, numeroDePerguntas);
    printf("--------------------------\n");
    


    return 0;
}