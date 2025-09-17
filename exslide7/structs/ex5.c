#include <stdio.h>

typedef struct Ponto {
    int x;
    int y;
    int z;
}ponto;

int main(){
    ponto v1 = {1,0,5};
    ponto v2 = {3,3,3};
    ponto v3 = {0,10,0};

    printf("y1: %d, y2: %d, y3: %d\n", v1.y, v2.y, v3.y);

    v1.z += 10;
    v2.z += 10;
    v3.z += 10;

    printf("x2: %d, y2: %d, z2: %d\n", v2.x, v2.y, v2.z);
    return 0;
}