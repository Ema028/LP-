#include <stdio.h>
#include <stdlib.h>

#define size 50
#define true 0

void get_int(char* string, int* num);
int compare(const void* a, const void* b);
int search(int arr[], int num, int tamanho);

int main()
{
    int temps[size];
    int media, acima_media = 0;
    for(int i = 0; i < size; i ++)
    {
       get_int("Qual a temperatura?\n", &temps[i]);
       media += temps[i];
    }
    media /= size;
    printf("média: %d\n", media);
    qsort(temps, size, sizeof(int), compare);
    acima_media = search(temps, media, size); //pega a lista ordenada e acha o index do 1 elemento acima da média
    printf("%d elementos acima da média.\n", size - acima_media); //size -1 (ultimo index) - acima_media(1 index) + 1(incluindo o 1 q foi tirado)
    return 0;
}

void get_int(char* string, int* num)
{
    printf("%s", string);
    scanf("%d", num);
}

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int search(int arr[], int num, int tamanho) //binary search
{
    if (arr[tamanho - 1] == num)
    {
        return size;//caso todas as temp são iguais
    }
    short int index = (tamanho - 1)/2;
    while(true)
    {
        if(arr[index] > num && arr[index - 1] < num){
            return num;
        }else if(arr[index] < num){
            index = (index + (tamanho - 1))/2;
        }else{
            index /= 2;
        }
    }
}