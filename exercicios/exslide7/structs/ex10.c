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
void desenhar_mapa(personagem* personagem, int size, char* map);
void print_mapa(char* xs, int linha, int coluna);

int main(){
    personagem personagens[3];
    char mapa[11][11] = {{' ','0','1','2','3','4','5','6','7','8','9'},
                        {'0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {'1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {'2',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {'3',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {'4',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {'5',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {'6',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {'7',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {'8',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {'9',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
    preenche_vetor(personagens, 3);
    desenhar_mapa(personagens, 3, &mapa[0][0]);
    print_mapa(&mapa[0][0], 11, 11);
    return 0;
}



void desenhar_mapa(personagem* personagem, int size, char* map){
    for(int i = 0; i < size; i++){
        *(map + 11*((personagem + i) -> posicao.x + 1) + ((personagem + i) -> posicao.y + 1)) = (personagem + i) -> id + '0';
    }
}

void print_mapa (char* xs, int linha, int coluna)
{
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("%c ", *(xs + i*coluna + j));
        }
        printf("\n");
    }

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
