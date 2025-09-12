/*#include <stdio.h>
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
*/

//versão básica
#include <stdio.h>

#define times 20

int get_int(char* string);
char* get_sized_string(char* text, char* nome);

int main()
{
    char nome1[255];
    char nome2[255];

    int maior_pont = 0;
    int menor_pont = 0;
    int tmp_pont = 0;

    char* tmp1 = NULL;
    char* tmp2 = NULL;

    for(int i = 0; i < times; i++)
    {
        tmp_pont = 0;
        tmp_pont += 3* get_int("Qual a quantidade de vitórias?");
        tmp_pont += get_int("Qual a quantidade de empates?");
        tmp_pont += 0* get_int("Qual a quantidade de derrotas?");
        if (i == 0){
            tmp1 = get_sized_string("Qual o nome do time", nome1);
            tmp2 = tmp1;
            maior_pont = tmp_pont;
            menor_pont = tmp_pont;
        }else{
            if(tmp_pont > maior_pont){
                tmp1 = get_sized_string("Qual o nome do time", nome1);
                maior_pont = tmp_pont;
            }else if(tmp_pont < menor_pont){
                tmp2 = get_sized_string("Qual o nome do time", nome2);
                menor_pont = tmp_pont;
            }
        }
    }

    printf("menor pontuação: %d, %s\nmaior pontuação: %d, %s", menor_pont, tmp1, maior_pont, tmp2);
    return 0;
}

int get_int(char* string)
{
    int num;
    printf("%s\n", string);
    scanf("%d", &num);
    return num;
}

char* get_sized_string(char* text, char* nome)
{
    printf("%s\n", text);
    scanf("%s", nome);
    return nome;
}
