#ifndef _ENUMNOR_H_
#define _ENUMNOR_H_

#include "comp.h"

#define MAX_LEN_STRING 128

const double EPSILON = 1e-8;
const int COEFFICIENTS_COUNT = 3;

enum class NumberOfRoots : char {
    UNKNOWN_NR,
    NOROOTS,
    ONEROOT,
    TWOROOTS,
    INF_ROOTS
};

struct tests_calc {
    NumberOfRoots nor = NumberOfRoots::UNKNOWN_NR;
    ComparisonStatus cs1 = ComparisonStatus::UNKNOWN_CS, cs2 = ComparisonStatus::UNKNOWN_CS;
    double result1 = NAN, result2 = NAN, a_coef = NAN, b_coef = NAN, c_coef = NAN;
};

struct tests_out {
    char command[MAX_LEN_STRING] = "";
    NumberOfRoots count_root = NumberOfRoots::UNKNOWN_NR;
    double result1 = NAN, result2 = NAN;
};

int Separator(void);

#endif // _ENUMNOR_H_
