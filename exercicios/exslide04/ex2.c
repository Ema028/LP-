#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 0
#define false 1

int eh_primo(int n);
int* todos_os_primos(int max);
int get_int(char* string);

int main()
{
    int n;
    n = get_int("diga um num:\n");
    int* primos = todos_os_primos(n);
    free(primos);
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

//guarda array primos para caso de expansão futura
int* todos_os_primos(int max)
{
    int* primos = malloc(max  * sizeof(int));
    printf("os primos entre 1 e %d são:\n", max);
    for(int i = 1; i <= max; i++)
    {
        if(eh_primo(i) == true)
        {
            primos[i - 1] = i;
            printf("%d ", i);
        }
    }
    return primos;
}

int get_int(char* string)
{
    int num;
    printf("%s\n", string);
    scanf("%d", &num);
    return num;
}
