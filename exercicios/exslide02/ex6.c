#include <stdio.h>

int get_int(char* text);

int main()
{
    int n, soma;
    n = get_int("Diga um número: ");
    soma = n * (n + 1) * (2 * n + 1) / 6;
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
