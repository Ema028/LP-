#include <stdio.h>
/*No struct cada membro têm a sua própria memória, o tamanho total da struct é a soma dos tamanhos dos membros, 
tornando possível usar todos os campos ao mesmo tempo.
Já na union todos os campos compartilham a mesma área de memória,
logo o tamanho total da union vai ser o tamanho do maior campo e só vai ser possível usar um campo por vez.*/

//exemplo de struct, um registro de personagem, que precisa guardar força, energia e experiência ao mesmo tempo.
struct Personagem {
    int forca;
    int energia;
    int experiencia;
};

//exemplo de union, um registro de pessoa, aqui faz sentido usar union, porque para identificar a pessoa só precisa de uma informação por vez, economizando memória.
union Ident {
    int RG;
    int CPF;
    char Nome[256];
};
