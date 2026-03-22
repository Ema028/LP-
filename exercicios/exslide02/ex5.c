#include <stdio.h>

int get_int(char* text);

int main()
{
    int n = -1;
    int soma = 0;
    while(n != 0)
    {
        n = get_int("Diga um número: ");
        soma += n;
    }
    printf("%d\n", soma);
    return 0;
}

int get_int(char* text)
{
	int num;
	printf("%s\n", text);
	scanf("%d", &num);
	return num;
}
