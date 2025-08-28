#include <stdio.h>
#include <assert.h>

#include "calculation.h"
#include "comp.h"


NumberOfRoots SolveGeneralQuadraticEquation(struct Equation* obj) {

    assert (obj != nullptr);

    NumberOfRoots result = NumberOfRoots::UNKNOWN_NR;

    if (ComparisonNumb((*obj).a_coef, 0.0) == ComparisonStatus::EQUAL) {
        result = LinearCalculator(obj);
    } else {
        result = QuadraticCalculator(obj);
    }

    return result;
}


NumberOfRoots LinearCalculator(struct Equation* obj) {

    assert (obj != nullptr);

    const double b = (*obj).b_coef;
    const double c = (*obj).c_coef;
    double* const x1 = &(*obj).x1;

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


NumberOfRoots QuadraticCalculator(struct Equation* obj) {

    assert (obj != nullptr);

    const double a = (*obj).a_coef;
    const double b = (*obj).b_coef;
    const double c = (*obj).c_coef;
    double* const x1 = &(*obj).x1;
    double* const x2 = &(*obj).x2;

    double      d       = NAN;
    double doubled_a    = NAN;

    d = pow(b, 2) - 4 * a * c;
    doubled_a = 2 * a;

    switch (ComparisonNumb(d, 0.0)) {
        case ComparisonStatus::FIRST:
        {
            double sqrtD = NAN;
            sqrtD = sqrt(pow(b, 2) - 4 * a * c);

            *x1 = (-b - sqrtD) / doubled_a;
            *x2 = (-b + sqrtD) / doubled_a;
            return NumberOfRoots::TWOROOTS;
        }
        case ComparisonStatus::EQUAL:
            *x1 = -b / doubled_a;
            return NumberOfRoots::ONEROOT;
        case ComparisonStatus::SECOND:
            return NumberOfRoots::NOROOTS;
        case ComparisonStatus::UNKNOWN_CS:
            printf("QuadraticCalculator [d] ComparisonNumb ERROR\n");
            return NumberOfRoots::NOROOTS;
        default: printf("QuadraticCalculator switch ERROR\n");
    }
}
