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
	int lista2[4] = {2, 5, 7, 8};
	struct Caixa* cabeca = constroi(lista, 5);
	struct Caixa* cabeca2 = constroi(lista2, 4);

	exibe(cabeca);
	cabeca = concatena(cabeca, cabeca2);
	exibe(cabeca);
	destroi(cabeca);
	return 0;
}

struct Caixa* rmRepet(struct Caixa* lista){
	if (lista == NULL || lista->prox == NULL) return lista;
	int compare = lista->valor;
	struct Caixa* tmp = lista;
	while(tmp->prox != NULL){
		if(compare == tmp->prox->valor){
			tmp->prox = tmp->prox->prox;
			break;
		}
		tmp = tmp->prox;
	}
	rmRepet(lista->prox);
	return lista;
}

struct Caixa* concatena (struct Caixa* l1, struct Caixa* l2){
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;

	struct Caixa* tmp = l1;
	while(tmp->prox != NULL){
		tmp = tmp->prox;
	}
	tmp->prox = l2;
	return rmRepet(l1);
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
