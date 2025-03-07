#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], str3[200];
    char busca[100];
    char *resultado;

    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    printf("\nTamanho da primeira string: %lu\n", strlen(str1));
    printf("Tamanho da segunda string: %lu\n", strlen(str2));

    strcpy(str3, str1); 
    strcat(str3, " "); 
    strcat(str3, str2);
    printf("\nStrings concatenadas: %s\n", str3);


    if (strcmp(str1, str2) == 0) {
        printf("\nAs strings sao iguais.\n");
    } else {
        printf("\nAs strings sao diferentes.\n");
    }

    printf("\nDigite uma substring para buscar na primeira string: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0';

    resultado = strstr(str1, busca);
    if (resultado != NULL) {
        printf("Substring encontrada na posicao: %ld\n", resultado - str1);
    } else {
        printf("Substring nao encontrada.\n");
    }

    return 0;
}