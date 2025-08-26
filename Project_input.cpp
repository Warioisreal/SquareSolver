#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "common.h"
#include "special_term_commands.h"


void InputTerm(double* a, double* b, double* c) {

    int coef_count = 0;

    printf("\nenter equation coefficients: a [space] b [space] c [ax^2 + bx + c = 0]\n");

    while (coef_count != COEFFICIENTS_COUNT) {
        coef_count = scanf("%lg %lg %lg", a, b, c);

        if ((coef_count == COEFFICIENTS_COUNT) && (CheckBuffer()) {
            printf("\ndata correct\n\n\\result/\n");
        } else {
            printf("\ndata incorrect, try enter data again\n"
                "\nenter equation coefficients: a [space] b [space] c [ax^2 + bx + c = 0]\n");
            coef_count = 0;
        }
    }
}


void InputFile(double* a, double* b, double* c) {

    char file_name[MAX_LEN_STRING] = "";
    FILE* file = nullptr;

    printf("\nenter file name\n");
    scanf("%s", file_name);
    CleanInputBuffer();
    file = fopen(file_name, "r");

    if (file == nullptr) {
        printf("read file error\n");
    } else {
        int coef_count = fscanf(file, "%lg %lg %lg", a, b, c);

        if (coef_count == COEFFICIENTS_COUNT) {
            printf("successful data read\n");
        } else {
            printf("data read ERROR\n");
        }
    }
    fclose(file);
}


void InputCoefficients(double* a, double* b, double* c, const ExecMode mode) {

    assert (a != nullptr);
    assert (b != nullptr);
    assert (c != nullptr);

    if (mode == ExecMode::NORMAL) {
        InputTerm(a, b, c);
    } else if (mode == ExecMode::FILE) {
        InputFile(a, b, c);
    } else {
        printf("Input mode ERROR\n");
    }
}
