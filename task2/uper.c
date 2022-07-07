#include <stdio.h>
#include "libconverter.h"

int upper() {
    char text[MAX_LIMIT];
    printf("Enter your text\n");
    scanf(" %99[^\n]", text);
    convert(text, 1);
    return 0;
}