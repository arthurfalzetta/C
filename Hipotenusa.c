#include <stdio.h>
#include <math.h>

int main(){
    
    double A;
    double B;
    double C;
    
    printf("Medida do lado A: ");
    scanf("%lf", &A);
    printf("Medida do lado B: ");
    scanf("%lf", &B);
    
    C = sqrt(pow(A,2)+pow(B,2));

    printf("A hipotenusa do seu triangulo mede: %.2lf", C);
    
    return 0;
}