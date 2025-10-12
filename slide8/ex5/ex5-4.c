#include <stdio.h>
#include <string.h>

void escreva_string (FILE* f, char* str);

int main()
{   
    FILE* file = fopen("ex4.txt", "w");
    if (file == NULL){
        printf("não conseguiu criar o arquivo\n");
        return 1;
    }

    for(int i = 0; i<10; i++){
        char string[32];
        printf("Diga uma palavra: ");
        scanf("%25s", string);

        escreva_string (file, string);
        fprintf(file, "\n");
    }

    fclose(file);
    return 0;
}

void escreva_string (FILE* f, char* str){
    int size = strlen(str);
    for (int i = 0; i < size; i++){
        fputc(str[i], f);
    }
}