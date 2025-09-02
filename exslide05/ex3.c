#include <stdio.h>
#include <stdlib.h>

void compra (int* conta, int valor);
int* check_conta (int* conta1, int* conta2);

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Modo de uso: ./nomedoarquivo conta1 conta2\n");
        return 1;
    }
    int compras[6] = {100, 50, 80, 30, 20};
    int conta1 = atoi(argv[1]);
    int conta2 = atoi(argv[2]);
    int i = 0;
    //não chegou ao fim do array
    while (compras[i] != '\0'){
        compra(check_conta(&conta1, &conta2), compras[i]);
        printf("conta 1: %d\nconta 2: %d\n", conta1, conta2);
        i++;
    }
    return 0;
}

void compra (int* conta, int valor)
{
    *conta -= valor;
}

int* check_conta (int* conta1, int* conta2)
{
    if (*conta1 > *conta2){
        return conta1;
    }else{
        return conta2;
    }
}