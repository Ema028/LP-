#include <stdio.h>

#define l 3
#define c 2

void preenche (int* xs, int linha, int coluna);
int get_int(char* string);
float media(int* xs, int linha, int coluna);

int main()
{
    int vec[l][c];
    preenche(&vec[0][0], l, c);
    printf("%f\n", media(&vec[0][0], l, c));
    return 0;
}

void preenche (int* xs, int linha, int coluna)
{
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            *(xs + i*coluna + j) = get_int("diga um número:");
        }
    }

}

int get_int(char* string)
{
    int num;
    printf("%s\n", string);
    scanf("%d", &num);
    return num;
}

float media(int* xs, int linha, int coluna)
{
    float media = 0;
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            media +=  *(xs + i*coluna + j);
        }
    }
    return media/(linha*coluna);
}
