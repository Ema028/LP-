#include <stdio.h>

enum Dia{
    SEGUNDA,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA
};

char* nome (enum Dia dia);

int main(){
    printf("%s\n%s\n%s\n%s\n%s\n", nome(SEGUNDA), nome(TERCA), nome(QUARTA), nome(QUINTA), nome(SEXTA));
    return 0;
}

char* nome (enum Dia dia){
    switch (dia){
        case SEGUNDA:
            return "Segunda";
        case TERCA:
            return "Terça";
        case QUARTA:
            return "Quarta";
        case QUINTA:
            return "Quinta";
        case SEXTA:
            return "Sexta";
    
        default:
            return "inválido";
    }
}