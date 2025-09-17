#include <stdio.h>

void concatena (char* d, char* o1, char* o2);
int tamanho(char* string);

int main()
{
    char palavra[10];
    char word[10];
    char concatenado[20];
    printf("diga uma palavra\n");
    scanf("%s", palavra);
    printf("diga uma palavra\n");
    scanf("%s", word);
    concatena(concatenado, palavra, word);
    printf("%s\n", concatenado);
}

int tamanho(char* string){
    int size = 0;
    while (string[size] != '\0')
    {
        size++;
    }
    return size;
}

void concatena (char* d, char* o1, char* o2){
    int i = 0;
    int tam1 = tamanho(o1);
    int tam2 = tamanho(o2) + tam1;
    while(i < tam1)
    {
        *(d + i) = *(o1 + i);
        i++; 
    }
    while (i < tam2)
    {
        *(d + i) = *(o2 + i - tam1);
        i++;
    }
}