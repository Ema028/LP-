#include <stdio.h>

struct carro{
    char modelo[20];
    char placa[10];
    int ano;
};

struct moto{
    char tipo[20];
    char placa[10];
    int cilindradas;
};

enum Sub{
    CARRO,
    MOTO
};

struct veiculo{
    enum Sub sub;
    union{
        struct carro carro;
        struct moto moto;
    };
};

void preenche (struct veiculo* p);
char* get_sized_string(char* text, char* nome);
int get_int(char* string);

int main()
{
    struct veiculo veiculo;
    preenche(&veiculo);
    if(veiculo.sub == MOTO){
        printf("\nMoto: %s\nPlaca: %s\ncilindradas: %d\n", veiculo.moto.tipo, veiculo.moto.placa, veiculo.moto.cilindradas);
    }else{
        printf("\nCarro: %s\nPlaca: %s\nAno: %d\n", veiculo.carro.modelo, veiculo.carro.placa, veiculo.carro.ano);
    }
    return 0;
}

char* get_sized_string(char* text, char* nome)
{
    printf("%s\n", text);
    scanf("%s", nome);
    return nome;
}

void preenche (struct veiculo* p)
{
    p-> sub = get_int("digite 1 para moto, 0 para carro\n");

    switch (p -> sub){
        case MOTO:
            get_sized_string("qual o tipo da moto?", p-> carro.modelo);
            get_sized_string("qual a placa da moto?", p -> carro.placa);
            p -> carro.ano = get_int("quantas cilindradas?\n");    
            break;
        case CARRO:
            get_sized_string("qual o modelo do carro?", p-> carro.modelo);
            get_sized_string("qual a placa do carro?", p -> carro.placa);
            p -> carro.ano = get_int("qual o ano do carro?\n");
            break;
        default:
            printf("tipo desconhecido\n");
    }
}

int get_int(char* string)
{
    int num;
    printf("%s", string);
    scanf("%d", &num);
    return num;
}