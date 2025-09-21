#include <stdio.h>

typedef struct Jogador{
    char nome[255];
    char posicao[255];
    int codigo_país;
    int camisa;
}jogador;

void print_jogador(jogador* player);
void print_string(char* frase, char* string);

int main(){
    jogador messi = {"Lionel Messi", "atacante", 54 ,10};
    jogador cr7 = {"Cristiano Ronaldo/CR7", "ponta-esquerda/atacante", 351, 7};
    jogador kaka = {"Ricardo Izecson dos Santos Leite/Kaká", "meio-campista", 55, 22};
    print_jogador(&messi);
    print_jogador(&cr7);
    print_jogador(&kaka);
    return 0;
}


void print_jogador(jogador* player){
    print_string("Nome do atleta: ", player -> nome);
    print_string("Posição do atleta: ", player -> posicao);
    printf("Código do país: %d\n", player ->codigo_país);
    printf("Número da camisa: %d\n\n", player -> camisa);
}

void print_string(char* frase, char* string){
    printf("%s", frase);
    int i = 0;
    while(string[i] != '\0'){
        printf("%c", string[i]);
        i++;
    }
    printf("\n");
}