#include <stdio.h>

#define true 1
#define false 0

struct Caixa {
  int valor;
  struct Caixa* prox;
};

void exibe (struct Caixa* caixa);
int contem (struct Caixa* lista, int valor);
void print_contem (struct Caixa* lista, int valor);
struct Caixa* remover (struct Caixa* lista, int valor);
struct Caixa* concatena (struct Caixa* l1, struct Caixa* l2);

int main(){
	struct Caixa c1, c2, c3, c4; struct Caixa d1, d2, d3;
	struct Caixa* cabeca1 = &c1; struct Caixa* cabeca2 = &d1;

	c1.valor = 1; c2.valor = 3; c3.valor = 9; c4.valor = 7;	d1.valor =2; d2.valor =5; d3.valor = 9;
	c1.prox=&c2; c2.prox=&c3; c3.prox=&c4; c4.prox=NULL;    d1.prox=&d2; d2.prox=&d3; d3.prox=NULL;
	exibe(cabeca1);
	exibe(cabeca2);
	exibe(concatena(cabeca1, cabeca2));
	return 0;
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
