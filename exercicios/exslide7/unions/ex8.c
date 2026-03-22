#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Anfibio{
    int patas;
    int espessura_pele;
    bool cauda;
}anfibio;

typedef struct Reptil{
    bool aquatico;
    int espessura_ovo;
    bool venenoso;
}reptil;

typedef struct Ave{
    int comprimento_bico;
    int frequencia_canto; //Hz
    bool voa;
}ave;

typedef struct Mamifero{
    int dentes;
    int vol_cerebro;
    int vel;
}mamifero;

enum tipo{
    MAMIFERO,
    AVE,
    ANFIBIO,
    REPTIL
};

typedef union Animais {
    mamifero mamifero;
    ave ave;
    anfibio anfibio;
    reptil reptil;
} animais;

struct Animal{
    char especie [256];
    char nome[256];
    enum tipo tipo;
    animais animais;
};

void exibe (struct Animal* animal);
char* print_bool(bool boolean);

int main(){
    struct Animal tucano = {.tipo = AVE, .animais.ave.comprimento_bico = 20, .animais.ave.voa = true, .animais.ave.frequencia_canto = 15000};
    strcpy(tucano.especie, "Tucano");
    strcpy(tucano.nome, "Tonhão");

    struct Animal jacare = {.tipo = REPTIL, .animais.reptil = {true, 3, false}};
    strcpy(jacare.especie, "Jacaré");
    strcpy(jacare.nome, "Jonas");

    struct Animal shihtzu = {.tipo = MAMIFERO, .animais.mamifero = {42, 300, 25}};
    strcpy(shihtzu.especie, "Cachorro/Shih Tzu");
    strcpy(shihtzu.nome, "Molly/Chewbacca");

    struct Animal sapo = {.tipo = ANFIBIO, .animais.anfibio = {4, 2, false}};
    strcpy(sapo.especie, "Sapo");
    strcpy(sapo.nome, "Sonia");

    struct Animal humano = {.tipo = MAMIFERO, .animais.mamifero = {32, 1350, 37}};
    strcpy(humano.especie, "Humano");
    strcpy(humano.nome, "Holly");

    struct Animal papagaio = {.tipo = AVE, .animais.ave = {7, 5000, true}};
    strcpy(papagaio.especie, "Papagaio");
    strcpy(papagaio.nome, "Pôncio");

    exibe(&tucano);
    exibe(&jacare);
    exibe(&shihtzu);
    exibe(&sapo);
    exibe(&humano);
    exibe(&papagaio);

    return 0;
}

void exibe(struct Animal* animal) {
    printf("Espécie: %s\nNome: %s\n", animal ->especie, animal->nome);

    switch (animal->tipo) {
        case MAMIFERO:
            printf("Mamífero:\n");
            printf("  Dentes: %d\n", animal->animais.mamifero.dentes);
            printf("  Volume cerebral: %d cm³\n", animal->animais.mamifero.vol_cerebro);
            printf("  Velocidade: %d km/h\n\n", animal->animais.mamifero.vel);
            break;

        case AVE:
            printf("Ave:\n");
            printf("  Comprimento do bico: %d cm\n", animal->animais.ave.comprimento_bico);
            printf("  Frequência do canto: %d Hz\n", animal->animais.ave.frequencia_canto);
            printf("  Voa: %s\n\n", print_bool(animal->animais.ave.voa));
            break;

        case ANFIBIO:
            printf("Anfíbio:\n");
            printf("  Patas: %d\n", animal->animais.anfibio.patas);
            printf("  Espessura da pele: %d mm\n", animal->animais.anfibio.espessura_pele);
            printf("  Tem cauda: %s\n\n", print_bool(animal->animais.anfibio.cauda));
            break;

        case REPTIL:
            printf("Réptil:\n");
            printf("  Aquático: %s\n", print_bool(animal->animais.reptil.aquatico));
            printf("  Espessura da casca do ovo: %d mm\n", animal->animais.reptil.espessura_ovo);
            printf("  Venenoso: %s\n\n", print_bool(animal->animais.reptil.venenoso));
            break;

        default:
            printf("Tipo desconhecido.\n");
    }
}

char* print_bool(bool boolean){
    if(boolean) return "sim";
    return "não";
}