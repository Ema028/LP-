#include <stdio.h>

#define dollar float
#define real float
#define euro float

typedef enum Sub{
    DOLLAR,
    REAL,
    EURO
}sub;

typedef struct Preco{
    sub moeda;
    union {
        dollar dol;
        real rs;
        euro eu;
    };
}preco;

void exibe(preco* valor);
void altera(preco* valor, sub new_moeda);

int main(){
    preco fatura;
    fatura.moeda = REAL;
    fatura.rs = 1;

    exibe(&fatura);

    altera(&fatura, EURO);
    altera(&fatura, REAL);
    altera(&fatura, DOLLAR);

    return 0;
}

void exibe(preco* valor){
    switch(valor -> moeda){
        case DOLLAR:
        printf("%.2f dólares\n", valor -> dol);
        break;
        case REAL:
        printf("%.2f reais\n", valor -> rs);
        break;
        case EURO:
        printf("%.2f euros\n", valor -> eu);
        break;
        default:
        printf("erro");
        return;
    }
}

//cotação: 5,34reais = 1dol; 1euro = 6,27reais
void altera(preco* valor, sub new_moeda){
    float tmp;
    const float cotacao_dol = 5.34;
    const float cotacao_euro = 6.27;
    
    //passa valor para reais
    switch (valor->moeda) {
        case DOLLAR:
            tmp = valor->dol * cotacao_dol;
            break;
        case EURO:
            tmp = valor->eu * cotacao_euro;
            break;
        case REAL:
            tmp = valor->rs;
            break;
    }

    //para a nova moeda
    switch (new_moeda) {
        case DOLLAR:
            valor->dol = tmp / cotacao_dol;
            break;
        case EURO:
            valor->eu = tmp / cotacao_euro;
            break;
        case REAL:
            valor->rs = tmp;
            break;
    }

    valor->moeda = new_moeda;
    exibe(valor);
}