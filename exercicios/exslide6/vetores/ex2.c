#include <stdio.h>

#define tam 5

void preenche (int* xs, int n);
void print_vec (int* xs, int n);
int get_int(char* string);
void remove (int* xs, int n, int index);

int main()
{
    int vec[tam];
    int I;

    preenche(vec, tam);
    print_vec(vec, tam);
    I = get_int("diga um index de 0 a 4");
    remove(vec, tam, I);
    print_vec(vec, tam);
    return 0;
}

void preenche (int* xs, int n)
{
    for(int i = 0; i < n; i++){
        *(xs + i) = get_int("diga um número:");
    }

}

int get_int(char* string)
{
    int num;
    printf("%s\n", string);
    scanf("%d", &num);
    return num;
}

void print_vec (int* xs, int n)
{
    for(int i = 0; i < n; i++){
        printf("%d ", *(xs + i));
    }
    printf("\n");
}

void remove (int* xs, int n, int index)
{
    for(int i = index; i < n - 1; i++)
    {
        *(xs + i) = *(xs + i + 1);
    }
    *(xs + n - 1) = 0;
}