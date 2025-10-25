#include <stdio.h>
#include <string.h>
#include <locale.h>

void ex1(void);
void ex2(void);
void ex4(void);
void erro(void);

int main()
{
    setlocale(LC_ALL,"portuguese"); 

    int opção;
    void (*opções[])() = {ex1, ex2, erro, ex4};
    printf("gostaria de executar o exercício 1, 2 ou 4?\n");
    scanf("%d", &opção);
    if(opção < 1  || opção > 4){
        opção = 3;
    }
    opções[opção - 1]();
    return 0;
}

void ex1()
{   
    setlocale(LC_ALL,"portuguese"); 

    char string[32];
    printf("Diga uma palavra: ");
    scanf("%25s", string);

    int size = strlen(string);

    FILE* file = fopen("ex1_6.txt", "wb");
    if (file == NULL){
        printf("não conseguiu criar o arquivo\n");
        return;
    }

    for (int i = 0; i < size; i++){
        fputc(string[i], file);
    }

    fclose(file);
}

void ex2()
{
    setlocale(LC_ALL,"portuguese"); 

    char string[32];
    FILE* file = fopen("ex1_6.txt", "rb");

    int read, i = 0;
    while((read = fgetc(file)) != EOF){
        string[i++] = read;
    }

    string[i] = '\0';
    printf("%s", string);
    fclose(file);
}

void ex4()
{   
    setlocale(LC_ALL,"portuguese"); 
    
    FILE* file = fopen("ex4_6.txt", "wb");
    if (file == NULL){
        printf("não conseguiu criar o arquivo\n");
        return;
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
}

void erro(void){
    printf("opção inválida\n");
}