#include <stdio.h>
#include <stdlib.h>

#define true 1

struct Caixa {
    int valor;
    struct Caixa* prox;
};

struct Caixa* constroi(int N);
void destroi(struct Caixa* cabeca);
void exibe(struct Caixa* caixa);

int main(){
	struct Caixa* cabeca = constroi(-1);
	exibe(cabeca);
	destroi(cabeca);
	return 0;
}

struct Caixa* constroi(int N){
	struct Caixa* cabeca = NULL;
	struct Caixa* aux = NULL;
	int num;
	scanf("%d", &num);

	while(num != N){
		struct Caixa* tmp = malloc(sizeof(struct Caixa));
		tmp -> valor = num;
		tmp -> prox = NULL;
		if(cabeca == NULL){
			cabeca = tmp;
			aux = cabeca;
		}else{
			aux->prox = tmp;
			aux = tmp;
		}
		scanf("%d", &num);
	}
	return cabeca;
}

void destroi(struct Caixa* cabeca){
	struct Caixa* tmp = cabeca;
	struct Caixa* aux = cabeca;
	while(tmp != NULL){
		tmp = tmp->prox;
		free(aux);
		aux = tmp;
	}
}

void exibe (struct Caixa* caixa){
	if (caixa == NULL) printf("nao existe\n");
	struct Caixa* cabeca = caixa;
	printf("%d\n", cabeca->valor);
	while(cabeca->prox != NULL){
		cabeca = cabeca->prox;	
		printf("%d\n", cabeca->valor);
	}
	printf("\n");
}
