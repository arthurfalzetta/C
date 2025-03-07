#include <stdio.h>
#include <ctype.h>

int main(){
    
    char unidade;
    float temp;

    printf("\nA temperatura esta em C ou F?: ");
    scanf("%c", &unidade);
    unidade = toupper(unidade);

    if (unidade == 'C'){
        printf("\nDigite a temperatura em C: ");
        scanf("%f", &temp);
        temp = (temp*9/5)+32;
        printf("\nA temperatura em F fica: %.1f", temp);

    }
    else if (unidade == 'F'){
        printf("\nDigite a temperatura em F: ");
        scanf("%f", &temp);
        temp = ((temp-32)*5)/9;
        printf("\nA temperatura em C fica: %.1f", temp);
    }
    else{
        printf("\n%c não e uma medida valida de temperatura", unidade);
    }
    
    


    
    
    
    return 0;
}