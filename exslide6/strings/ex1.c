#include <stdio.h>

int tamanho(char* string);

int main()
{
    char palavra[10];
    printf("diga uma palavra\n");
    scanf("%s", palavra);
    printf("%d\n", tamanho(palavra));
}

int tamanho(char* string){
    int size = 0;
    while (string[size] != '\0')
    {
        size++;
    }
    return size;
}