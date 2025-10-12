#include <stdio.h>
#include <string.h>

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

        int size = strlen(string);

        for (int i = 0; i < size; i++){
            fputc(string[i], file);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return 0;
}