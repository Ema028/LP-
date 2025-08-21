#include <stdio.h>
#include <stdlib.h>

int get_int(char* string);
char* get_sized_string(char* text, char* string, int size);
int compare(const void* a, const void* b); // function pointer a ser passado para qsort

typedef struct time{
    // 15 char + \0
    char nome[16];
    int pontos;
    int id;
}time;

int main() 
{
    //alocar memoria array de times e array temporario para organizar pontos
    time* times = malloc(20 * sizeof(time));
    time* tmp = calloc(20, sizeof(time)); //inicializar valores com zero
    int pontos = 0;
    for(int i = 0; i < 20; i++)
    {
        get_sized_string("Qual o nome do time", times[i].nome, 16);
        pontos += 3* get_int("Qual a quantidade de vitórias?");
        pontos += get_int("Qual a quantidade de empates?");
        pontos += 0* get_int("Qual a quantidade de derrotas?");
        times[i].pontos = tmp[i].pontos = pontos;
        times[i].id = tmp[i].id = i;
    }
    qsort(tmp, 20, sizeof(time), compare);
    // 10 primeiros de tmp são os com menos pontos e 10 ultimos com mais pontos
    for(int i = 0; i < 20; i++)
    {
        printf("%s: %d pontos\n", times[tmp[i].id].nome, times[tmp[i].id].pontos);
    }
    free(tmp);
    free(times);
    return 0;
}


int get_int(char* string)
{
    int num;
    printf("%s\n", string);
    scanf("%d", &num);
    return num;
}

char* get_sized_string(char* text, char* string, int size)
{
    printf("%s\n", text);
    //fgets ao inves de scan("%15s", &string) caso time são paulo
    fgets(string, size, stdin);
    return string;
}

int compare(const void* a, const void* b)
{
    //comparar pontos entre 2 times
    time* A = (time*)a;
    time* B = (time*)b;
    return (A->pontos - B->pontos);
}