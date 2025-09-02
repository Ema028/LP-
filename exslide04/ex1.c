#include <stdio.h>
#include <math.h>

#define true 0
#define false 1

int eh_primo(int n);

int main()
{
    int n;
    n = get_int("diga um num:\n");
    return 0;
}

int eh_primo(int n)
{
    for(int i = 2; i<=sqrt(n); i++)
    {
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int get_int(char* string)
{
    int num;
    printf("%s\n", string);
    scanf("%d", &num);
    return num;
}