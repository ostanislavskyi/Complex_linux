#include <stdio.h>
#include "libconverter.h"

int lower() {
    char text[MAX_LIMIT];
    printf("Enter your text\n");
    scanf(" %99[^\n]", text);
    convert(text, 2);
    return 0;
}