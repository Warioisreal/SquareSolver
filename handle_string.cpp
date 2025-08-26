#include <string.h>
#include <stdio.h>

#include "handle_string.h"


int CalcNumberCharInString(const char symbol, const char string[MAX_LEN_STRING]) {
    const size_t string_size = sizeof(string) / sizeof(string[0]);
    size_t result = 0;
    for (size_t i = 0; i < string_size; i++) {
        printf("%zu %c %c\n", i + 1, symbol, string[i]);
        if (symbol == string[i]) {
            result++;
        }
    }

    return result;
}
