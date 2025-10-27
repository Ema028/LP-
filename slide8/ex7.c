#include <stdio.h>
#include <string.h>

struct Pessoa {
    int  idade;
    char nome[64];
    int  peso;
};

void preenche (struct Pessoa* p);
void salvar_pessoa(struct Pessoa* p, int n);
int get_int(char* string);
char* get_sized_string(char* text, char* nome);
void load_pessoas(struct Pessoa* p, int n);

//O tamanho final do arquivo é proporcional ao tamanho fixo da struct, não ao tamanho real do nome digitado - ex 8

int main()
{
    struct Pessoa pessoas[10];
    load_pessoas(pessoas, 10);

    for (int i = 0; i < 10; i++) {
        printf("\nPessoa %d:\n", i + 1);
        preenche(&pessoas[i]);
    }

    salvar_pessoa(pessoas, 10);
    return 0;
}

void preenche (struct Pessoa* p)
{
    p -> idade = get_int("qual a idade?\n");
    p -> peso = get_int("qual o peso(em Kg)?\n");
    get_sized_string("qual o nome?", p->nome);
}

int get_int(char* string)
{
    int num;
    printf("%s", string);
    scanf("%d", &num);
    return num;
}

char* get_sized_string(char* text, char* nome)
{
    printf("%s\n", text);
    scanf("%s", nome);
    return nome;
}

void salvar_pessoa(struct Pessoa*p, int n)
{   
    FILE* file = fopen("ex7.bin", "wb");
    if (file == NULL){
        printf("não conseguiu criar o arquivo\n");
        return;
    }

    fwrite(p, sizeof(struct Pessoa), n, file);
    fclose(file);
}

void load_pessoas(struct Pessoa* p, int n)
{
    FILE* file = fopen("ex7.bin", "rb");
    if (file == NULL){
        printf("não há pessoas criadas\n");
        return;
    }

    fread(p, sizeof(struct Pessoa), n, file);
    fclose(file);
}