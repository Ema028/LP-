#include <stdio.h>

#define dollar 3.17//comando preprocessamento def dollar para real ratio
//preço bom <= 1000

int get_int(char* text);

int main()
{
    int preco;
    preco = get_int("Qual o preço do celular em dólares?\n");
    preco *= dollar;
    if(preco <= 1000){
        printf("BOM NEGÓCIO\n");
    }
    return 0;
}

int get_int(char* text)
{
	int num;
	printf("%s\n", text);
	scanf("%d", &num);
	return num;
}
