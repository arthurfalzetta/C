#include <stdio.h>

int main(){

    const double PI = 3.14159;
    double raio;
    double circunferencia;
    double area;

    printf("\nQual o raio do seu circulo? ");
    scanf("%lf", &raio);

    circunferencia = 2*PI*raio;
    area = PI*raio*raio;

    printf("A circunferencia do seu circulo mede: %.2lf", circunferencia);
    printf("\nA area do seu circulo mede: %.2lf", area);


    return 0;
}