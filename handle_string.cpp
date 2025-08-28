#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "handle_string.h"
#include "special_commands.h"


size_t CalcNumberCharInString(const char symbol, const char* string) {

    assert (string != nullptr);

    const size_t string_size = strnlen(string, MAX_LEN_STRING);
    size_t result = 0;
    for (size_t i = 0; i < string_size; i++) {
        if (symbol == string[i]) {
            result++;
        }
    }

    return result;
}


void FileName(char* filename, const char* mode) {

    if (fgets(filename, MAX_LEN_STRING, stdin) != nullptr) {

        size_t len = strnlen(filename, MAX_LEN_STRING);

        if (len == 1) {
            strncpy(filename, mode, MAX_LEN_STRING);
        } else if (len > 0 && (filename[len - 1] == '\n')) {
            filename[len - 1] = '\0';
            len--;
            CleanInput(stdin);
        }
    } else {
        printf("\nfgets ERROR, use default filename\n");
        strncpy(filename, mode, MAX_LEN_STRING);
    }
}
