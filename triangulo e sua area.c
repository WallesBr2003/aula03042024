#include <stdio.h>
#include <stdlib.h>

    int main(int argc, char *argv[]) {
int altura, linha, coluna, area , base;


    printf("Digite a altura do triangulo:");
    scanf("%d", &altura);
    

    for (linha = 0; linha < altura; linha++) {
        for (coluna = 0; coluna <= linha; coluna++) {
            printf("#");
            area++;
        }
        printf("\n");
    };
    
    area = (altura * altura)/2;
    printf("\n Area do triangulo = %.2d \n" ,area);
    
};


    



