#include <stdio.h>
#include <stdlib.h>

struct Caixa {
    int valor;
    struct Caixa* prox;
};

struct Caixa* constroi(int A[], int N);
void destroi(struct Caixa* cabeca);
void exibe(struct Caixa* caixa);
struct Caixa* concatena (struct Caixa* l1, struct Caixa* l2);

int main(){
	int lista[5] = {1,3,9,7,5};
	struct Caixa* cabeca = constroi(lista, 5);
	struct Caixa* cabeca2 = constroi(lista, 5);

	exibe(cabeca);
	exibe(concatena(cabeca, cabeca2));
	destroi(cabeca);
	destroi(cabeca2);
	return 0;
}

struct Caixa* concatena (struct Caixa* l1, struct Caixa* l2){
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;

	struct Caixa* tmp = l1;
	while(tmp->prox != NULL){
		tmp = tmp->prox;
	}
	tmp->prox = l2;
	return l1;
}

struct Caixa* constroi(int A[], int N){
	if (N==0) return NULL;

	struct Caixa* cabeca = NULL;
	struct Caixa* aux = NULL;

	for(int i = 0; i<N; i++){
		struct Caixa* tmp = malloc(sizeof(struct Caixa));
		tmp -> valor = A[i];
		tmp -> prox = NULL;
		if(cabeca == NULL){
			cabeca = tmp;
			aux = cabeca;
		}else{
			aux->prox = tmp;
			aux = tmp;
		}
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
