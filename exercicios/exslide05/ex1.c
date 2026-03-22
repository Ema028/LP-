#include <stdio.h>

int get_int(char* string);

int main()
{
    int a, b;
    int* c;
    a = get_int("diga um num:\n");
    b = get_int("diga um num:\n");
    if(a > b){
        c = &a;
    }else{
        c = &b;
    }
    *c -= 50;
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
