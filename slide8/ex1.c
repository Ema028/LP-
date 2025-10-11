#include <stdio.h>
#include <string.h>

int main()
{   
    char string[32];
    printf("Diga uma palavra: ");
    scanf("%s", string);

    int size = strlen(string);

    FILE* file = fopen("ex1.txt", "w");
    if (file == NULL){
        printf("não conseguiu criar o arquivo\n");
        return 1;
    }

    for (int i = 0; i < size; i++){
        fputc(string[i], file);
    }

    fclose(file);
    return 0;
}