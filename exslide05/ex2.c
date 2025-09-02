#include <stdio.h>
#include <stdlib.h>

void compra (int* conta, int valor);

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Modo de uso: ./nomedoarquivo conta1 conta2\n");
        return 1;
    }
    int conta1 = atoi(argv[1]);
    int conta2 = atoi(argv[2]);
    if (conta1 > conta2){
        compra(&conta1, 500);
    }else{
        compra(&conta2, 500);
    }

    printf("conta 1: %d\nconta 2: %d\n", conta1, conta2);
    return 0;
}

void compra (int* conta, int valor)
{
    *conta -= valor;
}