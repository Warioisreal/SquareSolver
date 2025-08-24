#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "Common.h"


int OutputRootsOrError(const NumberOfRoots Nroots, const double x1, const double x2) {

    assert (isfinite(x1));
    assert (isfinite(x2));

    switch (Nroots) {
        case NumberOfRoots::NOROOTS: printf("no real roots\n");
            break;
        case NumberOfRoots::ONEROOT: printf("root: %lg\n", x1);
            break;
        case NumberOfRoots::TWOROOTS: printf("roots:\nx1: %lg x2: %lg\n", x1, x2);
            break;
        case NumberOfRoots::INF_ROOTS: printf("inf roots\n");
            break;
        case NumberOfRoots::UNKNOWN_NR: printf("OUT default Nroots ERROR\n");
            break;
        default: printf("OUT switch ERROR\n");
    }

    return 0;
}
