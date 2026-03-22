#include <stdio.h>

#define true 1
#define false 0
#define TAM_MAX 100

struct Caixa {
  int valor;
  struct Caixa* prox;
};

/* como não é permitido alocação dinâmica de memória 
 * e precisa ser uma assinatura específica
 * (sem passar um ponteiro para uma caixa já criada),
 * usa uma reserva global de caixas vazias para funcionar */
int usados = 0;
struct Caixa caixas[TAM_MAX];

void exibe (struct Caixa* caixa);
int contem (struct Caixa* lista, int valor);
void print_contem (struct Caixa* lista, int valor);
struct Caixa* remover (struct Caixa* lista, int valor);
struct Caixa* insere (struct Caixa* lista, int valor);

int main(){
	struct Caixa c1, c2, c3, c4, c5;
	struct Caixa* cabeca = &c1;
	c1.valor = 1; c2.valor = 3; c3.valor = 5; c4.valor = 7; c5.valor = 9;
	c1.prox=&c2; c2.prox=&c3; c3.prox=&c4; c4.prox=&c5; c5.prox=NULL;
	exibe(cabeca);
	insere(cabeca, 2);
	exibe(cabeca);
	cabeca = insere(cabeca,0);
	exibe(cabeca);
	return 0;
}

struct Caixa* insere (struct Caixa* lista, int valor){
	if (lista == NULL) return lista;
	if (usados == TAM_MAX - 1){
		printf("memória cheia\n");
		return lista;
	}

	struct Caixa* aux = &caixas[usados];
	usados++;
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

struct Caixa* remover (struct Caixa* lista, int valor){
	if(lista->valor == valor){
		lista = lista->prox;
		return lista;
	}
	struct Caixa* tmp = lista;
	while (tmp->prox != NULL){
		if(tmp->prox->valor == valor){
			tmp->prox = tmp->prox->prox;
			return lista;
		};
		tmp = tmp->prox;
	}
	return lista;	
}

void print_contem (struct Caixa* lista, int valor){
	if(contem(lista, valor)){
		printf("%d esta na lista\n", valor);
	}else{
		printf("%d nao esta na lista\n", valor);
	}
}

int contem (struct Caixa* lista, int valor){
	struct Caixa* tmp = lista;
	while (tmp != NULL){
		if(tmp->valor == valor) return true;
		tmp = tmp->prox;
	}
	return false;
}

void exibe (struct Caixa* caixa){
	struct Caixa* cabeca = caixa;
	printf("%d\n", cabeca->valor);
	while(cabeca->prox != NULL){
		cabeca = cabeca->prox;	
		printf("%d\n", cabeca->valor);
	}
	printf("\n");
}
