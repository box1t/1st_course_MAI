#include <stdio.h>
#include <math.h>
#include <float.h>

double func1(double x) {
    return exp(x) + log(x) - 10 * x;
}

double derivative_func1(double x) {
    return exp(x) + 1 / x - 10;
}

double func2(double x) {
    return cos(x) - exp(-pow(x, 2) / 2) + x - 1;
}

double derivative_func2(double x) {
    return -sin(x) + x * exp(-pow(x, 2) / 2) + 1;
}

double Newton(double f(double), double d_f(double), double a, double b) {
    double x = b;
    while (fabsl(f(x) / d_f(x)) >= DBL_EPSILON) {
         x -= f(x) / d_f(x);
    }
    return x;
}

double Dichotomy(double f(double), double a, double b) {
    double c = 0;
    while (f(c) != 0 && fabsl(b - a) > DBL_EPSILON) {
        c = (a + b) / 2;
        (f(c) * f(a) > 0) ? (a = c) : (b = c);
    }
    return c;
}

int main() {
    printf("*----------------------------------*\n");
    printf("*-----------Variant(#1)------------*\n");   
    printf("*``````````````````````````````````*\n");
    printf("     exp(x) + log(x) - 10 * x  \n");
    printf("*----------------------------------*\n");
    printf("Newton Method value: %f\n", Newton(func1, derivative_func1, 3, 4));
    printf("Dichotomy Method value: %f\n", Dichotomy(func1, 3, 4));
    printf("*----------------------------------*\n");
    printf("*-----------Variant(#2)------------*\n");    
    printf("*``````````````````````````````````*\n");
    printf("cos(x) - exp(-pow(x, 2) / 2) + x - 1\n");
    printf("*``````````````````````````````````*\n");
    printf("Newton Method value: %f\n", Newton(func2, derivative_func2, 1, 2));
    printf("Dichotomy Method value: %f\n", Dichotomy(func2, 1, 2));
    printf("*----------------------------------*\n");
    
}
