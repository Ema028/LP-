#include <stdio.h>

typedef struct Personagem {
    int forca;
    int energia;
    int experiencia;
}personagem;

int main()
{
    personagem per1 = {10, 50, 30};

    personagem per2;
    per2.forca = 18;
    per2.energia = 20;
    per2.experiencia = 25;

    printf("personagem 1: %d força, %d energia, %d experiência\n", per1.forca, per1.energia, per1.experiencia);
    printf("personagem 2: %d força, %d energia, %d experiência\n", per2.forca, per2.energia, per2.experiencia);
    return 0;
}
