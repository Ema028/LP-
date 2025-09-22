#include <stdio.h>

typedef struct Ponto {
    int x;
    int y;
}ponto;

void preenche (ponto* p);
int get_int(char* string);
int preenche_vetor (ponto* vetor, int size);
int squared_distance (ponto* ponto);

int main(){
    ponto pontos[10];
    int i = preenche_vetor (pontos, 10);
    printf("(%d, %d)\n", pontos[i].x, pontos[i].y);
    return 0;
}

void preenche (ponto* p)
{
    p -> x = get_int("qual a coordenada?\n");
    p -> y = get_int("qual a coordenada?\n");
}

int get_int(char* string)
{
    int num;
    printf("%s", string);
    scanf("%d", &num);
    return num;
}

int preenche_vetor (ponto* vetor, int size)
{
    int maior_dist_quadrada = 0;
    int index = 0;
    for(int i = 0; i < size; i++){
        preenche(vetor + i);
        if (squared_distance(vetor + i) > maior_dist_quadrada){
            maior_dist_quadrada = squared_distance(vetor + i);
            index = i;
        }
    }
    return index;
}

int squared_distance (ponto* ponto)
{
    //distancia quadrada de (0,0) = x² + y²
    return (((ponto -> x) * (ponto -> x)) + ((ponto -> y) * (ponto -> y)));
}