#include <stdio.h>

union Ponto {
    struct {
        int x;
        int y;
        int z;
    };
    int vec[3];
};

int main(){
    union Ponto pt;
    pt.vec[0] = 10;
    pt.vec[1] = 20;
    pt.vec[2] = 30;
    printf("(%d,%d,%d)\n", pt.x, pt.y, pt.z);
    return 0;
}