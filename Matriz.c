#include <stdio.h>

const int TAMANHO = 3;

void lerMatriz(int matriz[TAMANHO][TAMANHO], char nome) {
    printf("Digite os valores da matriz %c (%dx%d):\n", nome, TAMANHO, TAMANHO);
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c[%d][%d]: ", nome, i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void exibirMatriz(int matriz[TAMANHO][TAMANHO], char nome) {
    printf("Matriz %c:\n", nome);
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrizes(int A[TAMANHO][TAMANHO], int B[TAMANHO][TAMANHO], int C[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            C[i][j] = 0;
            for (int k = 0; k < TAMANHO; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void subtrairMatrizes(int A[TAMANHO][TAMANHO], int B[TAMANHO][TAMANHO], int C[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void somarMatrizes(int A[TAMANHO][TAMANHO], int B[TAMANHO][TAMANHO], int C[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void transporMatriz(int matriz[TAMANHO][TAMANHO], int transposta[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
}

int main() {
    int A[TAMANHO][TAMANHO], B[TAMANHO][TAMANHO], C[TAMANHO][TAMANHO];
    int opcao;

    lerMatriz(A, 'A');
    lerMatriz(B, 'B');

    do {
        printf("\nMenu de Opcoes:\n");
        printf("(1) C = A * B\n");
        printf("(2) C = A - B\n");
        printf("(3) C = A + B\n");
        printf("(4) A Transposta da matriz C, sendo que C = A * B\n");
        printf("(5) Sair do Programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                multiplicarMatrizes(A, B, C);
                exibirMatriz(C, 'C');
                break;
            case 2:
                subtrairMatrizes(A, B, C);
                exibirMatriz(C, 'C');
                break;
            case 3:
                somarMatrizes(A, B, C);
                exibirMatriz(C, 'C');
                break;
            case 4:
                multiplicarMatrizes(A, B, C);
                int transposta[TAMANHO][TAMANHO];
                transporMatriz(C, transposta);
                exibirMatriz(transposta, 'T');
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}