#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char tabuleiro[3][3];
const char JOGADOR = 'X';
const char COMPUTADOR = 'O';

void apagaTabuleiro();
void printTabuleiro();
int verificaCasaLivre();
void vezDoJogador();
void vezDoComputador();
char verificaVencedor();
void printVencedor(char);

int main()
{
    char vencedor = ' ';
    char resposta = ' ';

    do
    {
        vencedor = ' ';
        resposta = ' ';
        apagaTabuleiro();

        while (vencedor == ' ' && verificaCasaLivre() != 0)
        {
            printTabuleiro();

            vezDoJogador();
            vencedor = verificaVencedor();
            if (vencedor != ' ' || verificaCasaLivre() == 0)
            {
                break;
            }
            
            vezDoComputador();
            vencedor = verificaVencedor();
            if (vencedor != ' ' || verificaCasaLivre() == 0)
            {
                break;
            }
        }

        printTabuleiro();
        printVencedor(vencedor);

        printf("\nQuer jogar mais uma vez? (Y/N): ");
        scanf(" %c", &resposta);
        resposta = toupper(resposta);
    } while (resposta == 'Y');
    
    printf("Obrigado por jogar!");

    return 0;
}

void apagaTabuleiro()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabuleiro[i][j] = ' ';
        }
        
    }
    
}

void printTabuleiro()
{
    printf(" %c | %c | %c ", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

int verificaCasaLivre()
{
    int casaLivre = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(tabuleiro[i][j] != ' ')
            {
                casaLivre--;
            }
        }
        
    }

    return casaLivre;
    
}

void vezDoJogador()
{
    int x;
    int y;
   
    do
    {
        printf("Escolha uma linha (1-3): ");
        scanf("%d", &x);
        x--;
        printf("Escolha uma colnua (1-3): ");
        scanf("%d", &y);
        y--;
    
        if (tabuleiro[x][y] != ' ')
        {
            printf("Jogada invalida!\n");
        }
        else
        {
            tabuleiro[x][y] = JOGADOR;
            break;
        }
    } while (tabuleiro[x][y] != ' ');
    
    
    
}

void vezDoComputador()
{
    srand(time(0));
    int x;
    int y;

    if (verificaCasaLivre() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (tabuleiro[x][y] != ' ');

        tabuleiro[x][y] = COMPUTADOR;
        
    }
    else
    {
        printVencedor(' ');
    }
    
    
}

char verificaVencedor()
{
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2])
        {
            return tabuleiro[i][0];
        }
        
    }

    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i])
        {
            return tabuleiro[0][i];
        }
        
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2])
        {
            return tabuleiro[0][0];
        }

    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0])
        {
            return tabuleiro[0][2];
        }

    return ' ';


    
}

void printVencedor(char vencedor)
{
    if (vencedor == JOGADOR)
    {
        printf("Voce venceu!!");
    }
    else if (vencedor == COMPUTADOR)
    {
        printf("Vitoria do computador, voce perdeu!");
    }
    else
    {
        printf("Deu velha!");
    }
    
    
}