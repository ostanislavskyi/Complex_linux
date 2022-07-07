#include "libcalc.h"


int summ(int a, int b) {
    return a + b;
}

int difference(int a, int b) {
    return a - b;
}

int product(int a, int b) {
    return a * b;
}

int fraction(int a, int b) {
    return a / b;
}

int factorial(int a) {
    int fact = 1;
    for (int i = 1; i <= a; i++) {
        fact = fact * i;
    }
    return fact;
}

int my_sqrt(int a) {
    int i = 0;
    int sqrt = 0;

    for (i = 1; i < a; i++) {
        if (i * i == a) {
            sqrt = i;
            break;
        }
    }

    return sqrt;
}