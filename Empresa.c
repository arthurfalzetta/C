#include <stdio.h>
#include <string.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Projeto
{
    char nome[100];
    char area[50];
    float valor;
    struct Data dataInicial;
    int duracao;
};

void cadastraProjeto(struct Projeto projetos[], int *numeroProjetos);
void consultaProjeto(struct Projeto projetos[], int numeroProjetos);

int main(){

    struct Projeto projetos[100];
    int numeroProjetos = 0;
    int opcao;

    do
    {
        printf("\nOpcoes:");
        printf("\n1. Cadastrar novo projeto");
        printf("\n2. Consultar projetos");
        printf("\n3. Fechar programa\n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            cadastraProjeto(projetos, &numeroProjetos);
        }
        else if (opcao == 2)
        {
            consultaProjeto(projetos, numeroProjetos);
        }
        else if (opcao == 3)
        {
            printf("Encerrando o programa");
        }
        
    } while (opcao != 3);
    

    return 0;
}


void cadastraProjeto(struct Projeto projetos[], int *numeroProjetos)
{
    struct Projeto novoprojeto;

    printf("\nNovo projeto!\n");

    printf("\nNome: ");
    scanf(" %[^\n]", novoprojeto.nome);

    printf("Area (Marketing, Operacional ou inovacao): ");
    scanf(" %s", novoprojeto.area);

    printf("Valor total: ");
    scanf("%f", &novoprojeto.valor);

    printf("Data de inicio (dd mm aaaa): ");
    scanf("%d %d %d", &novoprojeto.dataInicial.dia, &novoprojeto.dataInicial.mes, &novoprojeto.dataInicial.ano);

    printf("Tempo de duracao (meses): \n");
    scanf("%d", &novoprojeto.duracao);

    projetos[*numeroProjetos] = novoprojeto;
    (*numeroProjetos)++;

    printf("Cadastro feito\n");
}


void consultaProjeto(struct Projeto projetos[], int numeroProjetos)
{
    if (numeroProjetos == 0)
    {
        printf("\nNao existem projetos cadastrados\n");
    }
    

    printf("\nProjetos:\n");
    for (int i = 0; i < numeroProjetos; i++)
    {
        printf("\nProjeto %d\n", i + 1);
        printf("Nome: %s\n", projetos[i].nome);
        printf("Area: %s\n", projetos[i].area);
        printf("Valor: R$%.2f\n", projetos[i].valor);
        printf("Data inicial: %02d/%02d/%04d\n", projetos[i].dataInicial.dia, projetos[i].dataInicial.mes, projetos[i].dataInicial.ano);
        printf("Duracao (meses): %d\n", projetos[i].duracao);
    }
    
}