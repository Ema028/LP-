#include <stdio.h>

#define line 23

int main(){
	int id;
	char ch;
	char idade[4];
	char estado[3];

	FILE* f = fopen("ex1.txt", "rb");
	if (f == NULL){
		printf("não foi possivel abrir o arquivo\n");
		return 1;
	}

	printf("qual id do usuario?(indice da linha)\n");
	scanf("%d", &id);
	if(id < 0){
		printf("registro nao encontrado\n");
		return 2;
	}

	if (fseek(f, (id - 1) * line, SEEK_SET) != 0) {
        printf("registro nao encontrado\n");
        fclose(f);
        return 3;
    }
	
	printf("Nome: ");

	
	ch = fgetc(f);
	while(ch != ' '){
		if(ch != EOF) printf("%c", ch);
		ch = fgetc(f);
	}
	fseek(f, (id - 1) * line, SEEK_SET);

    fseek(f, 9, SEEK_CUR);
    fread(idade, 1, 3, f);
	idade[4] = '\0';
    printf("\nIdade: %s\n", idade);


    fseek(f, 7, SEEK_CUR);
    fread(estado, 1, 2, f);
	estado[3] = '\0';
    printf("Estado: %s\n", estado);

	fclose(f);
	return 0;
} 
