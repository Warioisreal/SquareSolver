#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "special_commands.h"


bool Check(FILE* file) {

    assert (file != nullptr);

    bool result = true;

    int val = fgetc(file);

    while (val != '\n') {
        result = result && isspace(val);
        val = fgetc(file);
    }

    return result;
}


void CleanInput(FILE* file) {

    assert (file != nullptr);

    while (fgetc(file) != '\n') {
        continue;
    }
}


void PrintSeparator(void) {
    printf("-------------------\n");
}
