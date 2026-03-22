#include <stdio.h>

typedef struct Personagem {
    int forca;
    int energia;
    int experiencia;
}personagem;

void preencheB (personagem* p);
int get_int(char* string);

int main()
{
    personagem per1;
    preencheB (&per1);
    personagem per2;
    preencheB (&per2);

    printf("personagem 1: %d força, %d energia, %d experiência\n", per1.forca, per1.energia, per1.experiencia);
    printf("personagem 2: %d força, %d energia, %d experiência\n", per2.forca, per2.energia, per2.experiencia);
    return 0;
}

void preencheB (personagem* p){
    p -> forca = get_int("qual a força do personagem?\n");
    p -> energia = get_int("qual a energia do personagem?\n");
    p -> experiencia = get_int("qual a experiência do personagem?\n");
}

int get_int(char* string)
{
    int num;
    printf("%s", string);
    scanf("%d", &num);
    return num;
}