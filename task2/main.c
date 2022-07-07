#include <stdio.h>
// #include "libconverter.h"

int upper();
int lower();

static void wellcom_func() {
    printf("Wellcome in my convertor\n");
    printf("Choose your action:\n \
    1. To upper\n \
    2. To lower\n");
    printf("Enter the number of operation:\n");

}


int main() {
    int op = 0;
    wellcom_func();
    scanf("%i", &op);
    fflush(stdout);
    fflush(stdin);
    if (op == 1)
        upper();
    else
        lower();
    return 0;
}