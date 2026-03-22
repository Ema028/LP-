#include <stdio.h>

long long tamanho(char* filename);

int main(){
	printf("%d bytes\n", tamanho("ex1.txt"));
	return 0;
}

long long tamanho(char* filename){
	long long tamanho = 0;
	int ch;
	FILE* f = fopen(filename, "rb");
	if (f == NULL){
		printf("nao foi possivel abrir o arquivo\n");
		return -1;
	}

	while ((ch = fgetc(f)) != EOF) {
        tamanho++;
    }

	fclose(f);
	return tamanho;
}
