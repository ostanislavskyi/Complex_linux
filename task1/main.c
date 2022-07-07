#include <stdio.h>
#include "libcalc.h"

static int wellcom_func() {
    printf("Wellcome in my calculator\n");
    printf("Choose your action:\n \
    1. Sum\n \
    2. Difference\n \
    3. Product\n \
    4. Fraction\n \
    5. factorial\n \
    6. Square\n");
    printf("Enter the number of operation:\n");

}


int main() {
    int operation = 0;
    int a = 0;
    int b = 0;
    int sqrt = 0;

    wellcom_func();
    scanf("%i", &operation);

    if (operation > 0 && operation < 5) {
        printf("Enter first integer number:\n");
        scanf("%i", &a);
        printf("Enter second integer number:\n");
        scanf("%i", &b);
    }
    else if(operation == 5 || operation == 6) {
        printf("Enter number:\n");
        scanf("%i", &a);
    }
    else {
        printf("Error, you choose incorect opration\n");
    }

    if (operation == 1)
    {
        printf("%i + %i = %i\n", a,b,summ(a, b));
    }
    if (operation == 2)
    {
        printf("%i - %i = %i\n", a,b, difference(a, b));
    }
    if (operation == 3)
    {
        printf("%i * %i = %i\n", a,b,product(a, b));
    }
    if (operation == 4)
    {
        if (b != 0)
            printf("%i / %i = %i\n", a,b, fraction(a, b));
        else {
            printf("Error, Division by zero\n");
        }
        
    }
    if (operation == 5)
    {
        if (a > 0)
            printf("%i! = %i\n", a, factorial(a));
        else {
            printf("Error, number must be > 0\n");
        }
    }
    if (operation == 6)
    {
        if (a > 0) {
            sqrt = my_sqrt(a);
            if (sqrt == 0) {
                printf("There is no integer sqrt root of %i\n", a);
            }
            else {
                 printf("sqrt root %i = %i\n", a, sqrt);
            }
        }
        else {
            printf("Error, number must be > 0\n");
        }
    }
}