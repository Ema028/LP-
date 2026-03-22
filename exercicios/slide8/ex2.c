#include <stdio.h>

int main()
{
    char string[32];
    FILE* file = fopen("ex1.txt", "r");

    int read, i = 0;
    while((read = fgetc(file)) != EOF){
        string[i++] = read;
    }

    string[i] = '\0';
    printf("%s", string);
    fclose(file);
    return 0;
}