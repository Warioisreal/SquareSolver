#include <stdio.h>

#include "buff_clear.h"


int Cleaner(void) {

    while (getchar() != '\n') {
        continue;
    }
    printf("Your input buffer is clean, Good Day!\n");

    return 0;
}
