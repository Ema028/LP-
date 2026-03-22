#include <stdio.h>

struct Caixa {
  int valor;
  struct Caixa* prox;
};

void exibe (struct Caixa* caixa);

int main(){
	struct Caixa c1, c2, c3, c4, c5;
	c1.valor = 1; c2.valor = 3; c3.valor = 9; c4.valor = 7; c5.valor = 5;
	c1.prox=&c2; c2.prox=&c3; c3.prox=&c4; c4.prox=&c5; c5.prox=NULL;
	exibe(&c1);
	return 0;
}

void exibe (struct Caixa* caixa){
	struct Caixa* cabeca = caixa;
	printf("%d\n", cabeca->valor);
	while(cabeca->prox != NULL){
		cabeca = cabeca->prox;	
		printf("%d\n", cabeca->valor);
	}
}
