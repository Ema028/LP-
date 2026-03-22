#include <stdio.h>

int get_int(char* string);
void swap(int* num1, int* num2);

int main()
{
    int a, b;
    int* c;
    a = get_int("diga um num:\n");
    b = get_int("diga um num:\n");
    swap(&a, &b);
    printf("num1: %d\nnum2: %d\n", a, b);
    return 0;
}

int get_int(char* string)
{
    int num;
    printf("%s\n", string);
    scanf("%d", &num);
    return num;
}

void swap(int* num1, int* num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}