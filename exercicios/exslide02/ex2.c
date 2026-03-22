#include <stdio.h>

int get_int(char* text);

int main(void)
{
	int num1 = get_int("Digite um número: ");
	int num2 = get_int("Digite um número: ");
	if(num1 > num2){
		printf("O maior é %d\n", num1);
	}else{
		printf("O maior é %d\n", num2);
	}
}

int get_int(char* text)
{
	int num;
	printf("%s\n", text);
	scanf("%d", &num);
	return num;
}
