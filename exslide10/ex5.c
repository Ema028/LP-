#include <stdio.h>
#include <stdlib.h>

struct Caixa {
    int valor;
    struct Caixa* prox;
};

struct Caixa* constroi(int A[], int N);
void destroi(struct Caixa* cabeca);
void exibe(struct Caixa* caixa);
struct Caixa* insere (struct Caixa* lista, int valor);
struct Caixa* remover (struct Caixa* lista, int valor);

int main(){
	int lista[5] = {1,3,9,7,5};
	struct Caixa* cabeca = constroi(lista, 5);
	exibe(cabeca);

	cabeca = insere(cabeca, 0);
	remover(cabeca,9);
	remover(cabeca,5);
	exibe(cabeca);

	insere(cabeca,9);
	insere(cabeca,5);
	cabeca = remover(cabeca,0);
	exibe(cabeca);
	destroi(cabeca);
	return 0;
}

struct Caixa* remover (struct Caixa* lista, int valor){
	if(lista->valor == valor){
		lista = lista->prox;
		return lista;
	}
	struct Caixa* tmp = lista;
	struct Caixa* aux = NULL;
	while (tmp->prox != NULL){
		if(tmp->prox->valor == valor){
			aux = tmp->prox;
			tmp->prox = tmp->prox->prox;
			free(aux);
			return lista;
		};
		tmp = tmp->prox;
	}
	return lista;	
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

//inserir ordenado(em listas já ordenadas)
struct Caixa* insere (struct Caixa* lista, int valor){
	struct Caixa* aux = malloc(sizeof(struct Caixa));
	aux->valor = valor;
	aux->prox = NULL;

    if (lista->valor > valor ){
        aux->prox = lista;
        lista = aux;
        return lista;
    }

    struct Caixa *tmp = lista;
    while (tmp->prox != NULL){
        if (tmp->prox->valor > valor){
            aux->prox = tmp->prox;
            tmp->prox = aux;
            return lista;
        }
        tmp = tmp->prox;
    }
    tmp->prox = aux;
    return lista;
}
