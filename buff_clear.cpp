#include <stdio.h>

#include "buff_clear.h"


int Cleaner(void) {

    int symbol = '\t';
    symbol = getchar();

    while (symbol != '\n') {
        symbol = getchar();
    }
    printf("Your input buffer is clean, Good Day!\n");

    return 0;
}
