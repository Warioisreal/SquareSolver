#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "common.h"
#include "comp.h"
#include "calculation.h"


NumberOfRoots SolveGeneralQuadraticEquation(const double a, const double b, const double c, double* const x1, double* const x2) {

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != nullptr);
    assert (x2 != nullptr);

    NumberOfRoots result = NumberOfRoots::UNKNOWN_NR;

    if (ComparisonNumb(a, 0.0) == ComparisonStatus::EQUAL) {
        result = LinearCalculator(b, c, x1);
    } else {
        result = QuadraticCalculator(a, b, c, x1, x2);
    }

    return result;
}


NumberOfRoots LinearCalculator(const double b, const double c, double* const x1) {

    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != nullptr);

    if ((ComparisonNumb(b, 0.0) == ComparisonStatus::EQUAL)) {
        if (ComparisonNumb(c, 0.0) == ComparisonStatus::EQUAL) {
            return NumberOfRoots::INF_ROOTS;
        } else {
            return NumberOfRoots::NOROOTS;
        }
    } else {
        *x1 = -c / b;
        return NumberOfRoots::ONEROOT;
    }
}


NumberOfRoots QuadraticCalculator(const double a, const double b, const double c, double* const x1, double* const x2) {

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != nullptr);
    assert (x2 != nullptr);

    double d = NAN;
    d = pow(b, 2) - 4 * a * c;

    switch (ComparisonNumb(d, 0.0)) {
        case ComparisonStatus::FIRST:
        {
            double sqrtD = NAN;
            sqrtD = sqrt(pow(b, 2) - 4 * a * c);

            *x1 = (-b - sqrtD) / (2 * a);
            *x2 = (-b + sqrtD) / (2 * a);
            return NumberOfRoots::TWOROOTS;
        }
        case ComparisonStatus::EQUAL:
            *x1 = -b / (2 * a);
            return NumberOfRoots::ONEROOT;
        case ComparisonStatus::SECOND:
            return NumberOfRoots::NOROOTS;
        case ComparisonStatus::UNKNOWN_CS:
            printf("QuadraticCalculator [d] ComparisonNumb ERROR\n");
            return NumberOfRoots::NOROOTS;
        default: printf("QuadraticCalculator switch ERROR\n");
    }
}
