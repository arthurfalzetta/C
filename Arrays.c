#include <stdio.h>
#include <string.h>

int main(){
    
    char carros[][10] = {"Mustang", "Corvette", "Fusca"};
    strcpy(carros[0], "Ferrari");

    for (int i = 0; i < sizeof(carros)/sizeof(carros[0]); i++)
    {
        printf("%s\n", carros[i]);
    }
    
    
    return 0;
}