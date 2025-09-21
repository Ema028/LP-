#include <stdio.h>

typedef struct carro{
    char modelo[20];
    char placa[10];
    int ano;
}carro;

void preenche (carro* p);
char* get_sized_string(char* text, char* nome);
int get_int(char* string);

int main()
{
    carro fusca;
    preenche(&fusca);
    printf("Carro: %s\nPlaca: %s\nAno: %d\n", fusca.modelo, fusca.placa, fusca.ano);
    return 0;
}

char* get_sized_string(char* text, char* nome)
{
    printf("%s\n", text);
    scanf("%s", nome);
    return nome;
}

void preenche (carro* p)
{
    get_sized_string("qual o modelo do carro?", (*p).modelo); //(*p).modelo == (p -> modelo)
    get_sized_string("qual a placa do carro?", p -> placa);
    p -> ano = get_int("qual o ano do carro?\n\n");
}

int get_int(char* string)
{
    int num;
    printf("%s", string);
    scanf("%d", &num);
    return num;
}