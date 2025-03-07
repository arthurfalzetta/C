#include <stdio.h>
#include <stdlib.h>

int main() {
    float valorDecimal;
    char *stringResultante;

    printf("Digite um valor decimal: ");
    scanf("%f", &valorDecimal);

    stringResultante = (char*)malloc(100 * sizeof(char));

    sprintf(stringResultante, "%.2f", valorDecimal);

    printf("Valor decimal: %.2f\n", valorDecimal);
    printf("String resultante: %s\n", stringResultante);

    free(stringResultante);

    return 0;
}