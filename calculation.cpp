#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "common.h"
#include "comp.h"
#include "calculation.h"


NumberOfRoots SolveGeneralQuadraticEquation(struct Coef_Roots* obj) {

    const Coef_Roots obj_cr {
        (*obj).a_coef,
        (*obj).b_coef,
        (*obj).c_coef,
        (*obj).root1,
        (*obj).root2
    };

    assert (isfinite (obj_cr.a_coef));
    assert (isfinite (obj_cr.b_coef));
    assert (isfinite (obj_cr.c_coef));

    assert (obj_cr.root1 != nullptr);
    assert (obj_cr.root2 != nullptr);

    NumberOfRoots result = NumberOfRoots::UNKNOWN_NR;

    if (ComparisonNumb(a, 0.0) == ComparisonStatus::EQUAL) {
        result = LinearCalculator(&obj_cr);
    } else {
        result = QuadraticCalculator(&obj_cr);
    }

    return result;
}


NumberOfRoots LinearCalculator(struct Coef_Roots* obj) {

    const double b = (*obj).b_coef;
    const double c = (*obj).c_coef;
    double* const x1 = (*obj).root1;

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


NumberOfRoots QuadraticCalculator(struct Coef_Roots* obj) {

    const double a = (*obj).a_coef;
    const double b = (*obj).b_coef;
    const double c = (*obj).c_coef;
    double* const x1 = (*obj).root1;
    double* const x2 = (*obj).root2;

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != nullptr);
    assert (x2 != nullptr);

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
