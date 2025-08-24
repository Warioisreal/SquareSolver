#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "Common.h"
#include "buff_clear.h"


int InputCoefficients(double* a, double* b, double* c) {

    assert (a != nullptr);
    assert (b != nullptr);
    assert (c != nullptr);

    assert (isfinite (*a));
    assert (isfinite (*b));
    assert (isfinite (*c));

    int ct = 0;

    printf("\nenter equation coefficients: a [space] b [space] c [ax^2 + bx + c = 0]\n");

    while (ct != COEFFICIENTSCOUNT) {
        ct = scanf("%lg %lg %lg", a, b, c);

        if (ct != COEFFICIENTSCOUNT) {

            Cleaner();

            printf("\ndata incorrect, try enter data again\n");
            printf("\nenter equation coefficients: a [space] b [space] c [ax^2 + bx + c = 0]\n");
        } else {
            if (getchar() == '\n') {
                printf("\ndata correct\n\n\\result/\n");
            } else {

                Cleaner();

                printf("\ndata incorrect, try enter data again\n");
                printf("\nenter equation coefficients: a[space]b[space]c [ax^2 + bx + c = 0]\n");
                ct = 0;
            }
        }

    }


    return 0;
}
