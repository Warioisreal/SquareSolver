#include <stdio.h>
#include <string.h>

#include "common.h"
#include "handle_math.h"
#include "handle_string.h"


void OutputRootsOrError(const NumberOfRoots Nroots, const double x1, const double x2, InteractionMode output_mode) {

    FILE* file = nullptr;

    if (output_mode == InteractionMode::NORMAL) {
        file = stdout;
    } else if (output_mode == InteractionMode::FILE) {

        printf("Enter output filename or press [enter] to skip\n");

        char file_name[MAX_LEN_STRING] = "";

        FileName(file_name, DEFAULT_FILENAME_OUTPUT);

        file = fopen(file_name, "w");
    }

    if (file == nullptr) {
        printf("write file error\n");
    } else {
        switch (Nroots) {
            case NumberOfRoots::NOROOTS:    fprintf(file, "no real roots\n");
                break;
            case NumberOfRoots::ONEROOT:    fprintf(file, "root: %lg\n", x1);
                break;
            case NumberOfRoots::TWOROOTS:   fprintf(file, "roots:\nx1: %lg x2: %lg\n", x1, x2);
                break;
            case NumberOfRoots::INF_ROOTS:  fprintf(file, "inf roots\n");
                break;
            case NumberOfRoots::UNKNOWN_NR: fprintf(file, "OUT default Nroots ERROR\n");
                break;
            default: fprintf(file, "OUT switch ERROR\n");
        }
    }
    if (output_mode == InteractionMode::FILE) {
        fclose(file);
    }
}
