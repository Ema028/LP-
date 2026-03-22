#include <stdio.h>
#include <string.h>

void escreva_string (FILE* f, char* str);

int main()
{   
    char string[32];
    printf("Diga uma palavra: ");
    scanf("%25s", string);

    FILE* file = fopen("ex1.txt", "w");
    if (file == NULL){
        printf("não conseguiu criar o arquivo\n");
        return 1;
    }

    escreva_string (file, string);

    fclose(file);
    return 0;
}

void escreva_string (FILE* f, char* str){
    int size = strlen(str);
    for (int i = 0; i < size; i++){
        fputc(str[i], f);
    }
}