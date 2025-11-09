#include <stdio.h>
#include <stdlib.h>

int main(){
	char arquivo[128];
	printf("qual o arquivo?\n");
	scanf("%127s", arquivo);

	FILE* f = fopen(arquivo, "r+");
	if (f == NULL){
		printf("nao foi possivel abrir o arquivo\n");
		return 1;
	}

	fseek(f, 0, SEEK_END);
	long tamanho = ftell(f);
	if(tamanho == -1){
		printf("tamanho do arquivo nao definido\n");
		return 2;
	}
	
	//salvar o que estavo do meio para baixo(n sobrescrever com fwrite)
	char* buffer = malloc(tamanho/2);
	fseek(f, tamanho/2, SEEK_SET);
	fread(buffer, sizeof(char), tamanho/2, f);

	fseek(f, tamanho/2, SEEK_SET);
    fwrite("|meio|", sizeof(char), 6, f);
    fwrite(buffer, sizeof(char), tamanho/2, f);

	free(buffer);
	return 0;
}
