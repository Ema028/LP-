#include <stdio.h>

#define milha 1.6 //comando preprocessamento def milha para km ratio
//vel boa entre 80 e 100 kph

int get_int(char* text);

int main()
{
    int vel;
    vel = get_int("Qual a velocidade atual do carro?\n");
    vel *= milha;
    if(vel <= 80){
        printf("ACELERE\n");
    }else if(vel >=100){
        printf("DESACELERE");
    }else{
        printf("MANTENHA");
    }
    return 0;
}

int get_int(char* text)
{
	int num;
	printf("%s\n", text);
	scanf("%d", &num);
	return num;
}
