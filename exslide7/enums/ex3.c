#include <stdio.h>

typedef enum Bool{
    False,
    True
}Boolean;

int main()
{
    Boolean on = True;
    if(on){
        printf("ligado");
    }
    return 0;
}