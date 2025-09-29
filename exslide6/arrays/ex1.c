#include <stdio.h>

#define L 3
#define C 2

void preenche (int arr[L][C], int l, int c);
int get_int(char* string);
void print_array(int arr[L][C], int l, int c);

int main()
{
    int vec[L][C];
    preenche(vec, L, C);
    print_array(vec, L, C);
    return 0;
}

void preenche (int arr[L][C], int l, int c){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            arr[i][j] = get_int("diga um número:");
        }
    }

}

void print_array(int arr[L][C], int l, int c){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int get_int(char* string)
{
    int num;
    printf("%s\n", string);
    scanf("%d", &num);
    return num;
}

