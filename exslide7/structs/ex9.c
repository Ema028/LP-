#include <stdio.h>

typedef struct Ponto {
    int x;
    int y;
}ponto;

typedef struct Personagem {
    int id;
    ponto posicao;
    int pontuacao;
}personagem;

void preenche (ponto* p);
void preencher (personagem* player);
int get_int(char* string);
void preenche_vetor (personagem* vetor, int size);

int main(){
    personagem personagens[10];
    preenche_vetor (personagens, 10);
    return 0;
}

void preenche (ponto* p)
{
    p -> x = get_int("qual a coordenada?\n");
    p -> y = get_int("qual a coordenada?\n");
}

void preencher (personagem* player){
    player -> id = get_int("qual o id do personagem?\n");
    player -> pontuacao = get_int("qual a pontuação do personagem?\n");
    preenche(&player->posicao);
}

int get_int(char* string)
{
    int num;
    printf("%s", string);
    scanf("%d", &num);
    return num;
}

void preenche_vetor (personagem* vetor, int size)
{
    for(int i = 0; i < size; i++){
        preencher(vetor + i);
    }
}
