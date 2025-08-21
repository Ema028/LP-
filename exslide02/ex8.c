#include <stdio.h>

int get_int(char* text);

int main()
{
    int num1, num2;
    num1 = get_int("Diga um número: ");
    num2 = get_int("Diga outro número: ");
    for(int i = num1 + 1; i < num2; i++)
    {
        printf("%d ", i);
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
