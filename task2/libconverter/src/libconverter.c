#include "libconverter.h"
#include <stdio.h>
#include <ctype.h>

void convert(char *text, int op) {
    printf("Converted text:\n");
    if (op == 1) {
        for (int i = 0; text[i] != 0; i++) {
            text[i] = toupper(text[i]);
        }
    }
    else {
        for (int i = 0; text[i] != 0; i++) {
            text[i] = tolower(text[i]);
        }
    }
    printf("%s\n", text);

}