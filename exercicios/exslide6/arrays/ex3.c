#include <stdio.h>

#define L 3
#define C 3

void preenche (int arr[L][C], int l, int c);
int get_int(char* string);
void print_array(int arr[L][C], int l, int c);
float determinante (int arr[L][C], int lc);

int main()
{
    int vec[L][C];
    preenche(vec, L, C);
    print_array(vec, L, C);
    printf("%.2f\n", determinante(vec, L));
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

void trocar_linha(float arr[L][C], int a, int b, int lc){
    for (int i = 0; i < lc; i++) {
        float tmp = arr[a][i];
        arr[a][i] = arr[b][i];
        arr[b][i] = tmp;
    }
}

float determinante (int arr[L][C], int lc){
    if(lc == 1) return arr[0][0]; //1 elemento
    if (lc == 2) return arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0]; //2 elementos
    //escalonamento precisa q valores do array sejam floats, copia array para buffer
    float ar[L][C];
    for (int i = 0; i < lc; i++){
        for (int j = 0; j < lc; j++){
            ar[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < lc; i++) {
        //Se o pivo é 0 troca a linha, se a linha é 0, det é 0
        int x = 1;
        while(ar[i][i] == 0){
            if(i == lc - 1){
                return 0;
            }
            trocar_linha(ar, i, i+x, lc);
            x++;
        }
        //zera coluna pivo
        for (int j = i + 1; j < lc; j++) { //linha pivo pra baixo
            float fator = (-1)*ar[j][i]/ar[i][i]; //somado zera elemento n*pivo=-x, somar n vezes linha pivo embaixo
            for (int k = i; k < lc; k++){ //coluna pivo pro lado
                ar[j][k] += fator * ar[i][k];
            }
        }
    }

    float det = 1;
    for (int i = 0; i < lc; i++) {
        det *= ar[i][i];
    }
    return det;
}