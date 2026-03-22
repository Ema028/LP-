#include <stdio.h>
#include <string.h>

typedef union Ident {
    unsigned int RG;
    unsigned int CPF;
    char Nome[256];
}pessoa;

int main(void){
    pessoa x, y, z;
    x.RG = 42282489;
    y.CPF = 180742805;
    strcpy(z.Nome, "Matias Alburqueqye Alves");

    printf("%d %d %s\n", x.RG, y.CPF, z.Nome);
}