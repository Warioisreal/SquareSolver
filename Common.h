#ifndef _ENUMNOR_H_
#define _ENUMNOR_H_

#include <math.h>
#include "comp.h"

#define MAX_LEN_STRING 128 // handle string

const double EPSILON = 1e-8; // handle math
const int COEFFICIENTS_COUNT = 3; // handle math

enum class NumberOfRoots : char { // handle math
    UNKNOWN_NR,
    NOROOTS,
    ONEROOT,
    TWOROOTS,
    INF_ROOTS
};

struct TestsCalc { //  handle tests или попробовать закинуть в юниты напрямую
    NumberOfRoots    nor = NumberOfRoots::UNKNOWN_NR;
    ComparisonStatus cs1 = ComparisonStatus::UNKNOWN_CS;
    ComparisonStatus cs2 = ComparisonStatus::UNKNOWN_CS;
    double   result1     = NAN;
    double   result2     = NAN;
    double    a_coef     = NAN;
    double    b_coef     = NAN;
    double    c_coef     = NAN;
};

struct TestsOut { //  handle tests или попробовать закинуть в юниты напрямую
    char command[MAX_LEN_STRING] = "";
    NumberOfRoots count_root     = NumberOfRoots::UNKNOWN_NR;
    double      result1          = NAN;
    double      result2          = NAN;
};

#endif // _ENUMNOR_H_
