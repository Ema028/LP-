#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRIANGLE 1
#define CIRCLE 2
#define RECTANGLE 3
#define PI 3.1415

float get_float(void);
void triangle(double* result);
void circle(double* result);
void rectangle(double* result);

int main(void)
{
    double area;
    void(*fp)(double*);
    printf("Digite 1 para um triângulo, 2 para um círculo e 3 para um retângulo\n");
    int forma;
    scanf("%i", &forma); fflush(stdout);
    switch(forma)
    {
        case TRIANGLE:
            fp = triangle;
            break;
        case CIRCLE:
            fp = circle;
            break;
        case RECTANGLE:
            fp = rectangle;
            break;
        default:
            return 0;
    }
    (fp)(&area);
    printf("\nA área é: %lf\n", area);
}

float get_float(void)
{
    float x;
    scanf("%f", &x); fflush(stdout);
    return x;
}

void triangle(double* result)
{
    printf("Digite o valor do lado 1:\n");
    float x = get_float();
    printf("Digite o valor do lado 2:\n");
    float y = get_float();
    printf("Digite o valor do lado 3:\n");
    float z = get_float();
    float p = (x + y + z)/2;
    *result = sqrt(p*(p - x)*(p - y)*(p - z));
}

void circle(double* result)
{
    printf("Qual o raio?\n");
    float r = get_float();
    *result = PI * r * r;
}

void rectangle(double* result)
{
    printf("Digite o valor da Base:\n");
    float b = get_float();
    printf("Digite o valor da altura:\n");
    float h = get_float();
    *result = b * h;
}
