#include <stdio.h>
#include <math.h>
#include <float.h>

long double function(long double x){
    return atan(x);
}

int main(){
    long double a = 0.0;
    long double b = 0.5;

    int number;

    printf("Enter your number: ");
    scanf("%d", &number);

    printf("\n*~~~~~*~~~~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~~~~~~~~~~~~~~~*\n");
    printf("|           Table of Taylor series values for f(x) = atan(x)              |\n");
    printf("*~~~~~*~~~~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~~~~~~~~~~~~~~~*\n");
    printf("|  x  | sum of Taylor series | value of function | number of iterations   |\n");
    printf("*~~~~~*~*~~~~~~~~~~~~~~~~~~~~*~~*~~~~~~~~~~~~~~~~*~~~~~~*~~~~~~~~~~~~~~~*~*\n");
    printf("| .3Lf  |       .19Lf           |       .19Lf           |   int value     |\n");
    printf("*~~~~~~~*~~~~~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~~~~~~*~*\n");

    long double step = (b - a) / (long double)number;
    long double taylor_row, sum;

    int iter = 0;

    for (long double x = a + step; x < b + step; x += step){
        for (int number = 0; number < 100; ++number) {
            taylor_row = pow(-1, number) * pow(x, 2 * number + 1) / (2 * number + 1);;
            sum += taylor_row;
            if (fabsl(sum - function(x)) < LDBL_EPSILON || iter > 100) {
                break;
            }
        }
        iter += 1;
        printf("| %.3Lf | %.19Lf | %.19Lf |       %d       |\n", x, sum, function(x), iter);
        sum = 0;
    }

    printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
    printf("| Machine epsilon (LDBL_EPSILON) accuracy (up to 10`th sign): %.10Le|\n", LDBL_EPSILON);
    printf("*~~~~~*~~~~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~~~~~~~~~~~~~~~*\n");
    return 0;
}
