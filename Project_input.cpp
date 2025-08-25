#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "common.h"
#include "special_term_commands.h"


int InputCoefficients(double* a, double* b, double* c) {

    assert (a != nullptr);
    assert (b != nullptr);
    assert (c != nullptr);

    int coef_count = 0;

    printf("\nenter equation coefficients: a [space] b [space] c [ax^2 + bx + c = 0]\n");

    while (coef_count != COEFFICIENTS_COUNT) {
        coef_count = scanf("%lg %lg %lg", a, b, c);

        if ((coef_count == COEFFICIENTS_COUNT) && (getchar() == '\n')) {
            printf("\ndata correct\n\n\\result/\n");
        } else {
            CleanInputBuffer();
            printf("\ndata incorrect, try enter data again\n"
                   "\nenter equation coefficients: a [space] b [space] c [ax^2 + bx + c = 0]\n");
            coef_count = 0;
        }
    }


    return 0;
}
