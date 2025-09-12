#include <stdio.h>

#define tam 5

void preenche (int* xs, int n);
int get_int(char* string);
float media(int* xs, int n);

int main()
{
    int vec[tam];
    preenche(vec, tam);
    printf("%f\n", media(vec, tam));
    return 0;
}

void preenche (int* xs, int n)
{
    for(int i = 0; i < n; i++){
        *(xs + i) = get_int("diga um número:");
    }

}

int get_int(char* string)
{
    int num;
    printf("%s\n", string);
    scanf("%d", &num);
    return num;
}

float media(int* xs, int n)
{
    float media = 0;
    for(int i = 0; i < n; i++)
    {
        media += *(xs + i);
    }
    return media/n;
}
