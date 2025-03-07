#include <stdio.h>

int main(){
    
    char operacao;
    double num1;
    double num2;
    double result;

    printf("Escolha uma operacao (+ - * /): ");
    scanf("%c", &operacao);

    printf("\nEscolha o primeiro numero: ");
    scanf("%lf", &num1);

    printf("\nEscolha o segundo numero: ");
    scanf("%lf", &num2);

    switch (operacao)
    {
    case '+':
        result = num1 + num2;
        printf("\nO resultado da sua operacao foi: %.2lf", result);
        break;
    case '-':
        result = num1 - num2;
        printf("\nO resultado da sua operacao foi: %.2lf", result);
        break;
    case '*':
        result = num1 * num2;
        printf("\nO resultado da sua operacao foi: %.2lf", result);
        break;
    case '/':
        result = num1 / num2;
        printf("\nO resultado da sua operacao foi: %.2lf", result);
        break;
    
    default:
        printf("Operacao nao valida");
        break;
    }

    
    return 0;
}