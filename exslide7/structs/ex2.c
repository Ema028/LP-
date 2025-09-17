#include <stdio.h>

typedef struct Personagem {
    int forca;
    int energia;
    int experiencia;
}personagem;

personagem preencheA ();
int get_int(char* string);

int main()
{
    personagem per1 = preencheA ();
    personagem per2 = preencheA ();

    printf("personagem 1: %d força, %d energia, %d experiência\n", per1.forca, per1.energia, per1.experiencia);
    printf("personagem 2: %d força, %d energia, %d experiência\n", per2.forca, per2.energia, per2.experiencia);
    return 0;
}

personagem preencheA (){
    personagem tmp;
    tmp.forca = get_int("qual a força do personagem?\n");
    tmp.energia = get_int("qual a energia do personagem?\n");
    tmp.experiencia = get_int("qual a experiência do personagem?\n");
    return tmp;
}

int get_int(char* string)
{
    int num;
    printf("%s", string);
    scanf("%d", &num);
    return num;
}