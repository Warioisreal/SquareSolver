#ifndef _UNIT_TESTS_H_
#define _UNIT_TESTS_H_

#include <string.h>

#include "comp.h"
#include "handle_math.h"
#include "handle_string.h"


struct TestsCalc {
    NumberOfRoots    nor = NumberOfRoots::UNKNOWN_NR;
    ComparisonStatus cs1 = ComparisonStatus::UNKNOWN_CS;
    ComparisonStatus cs2 = ComparisonStatus::UNKNOWN_CS;
    double   result1     = NAN;
    double   result2     = NAN;
    double    a_coef     = NAN;
    double    b_coef     = NAN;
    double    c_coef     = NAN;
};

struct TestsOut {
    char command[MAX_LEN_STRING] = "";
    NumberOfRoots count_root     = NumberOfRoots::UNKNOWN_NR;
    double      result1          = NAN;
    double      result2          = NAN;
};

const struct TestsCalc test_lin[] = {
    {NumberOfRoots::ONEROOT,    ComparisonStatus::EQUAL,        ComparisonStatus::UNKNOWN_CS,   2,    NAN,  0,  2,  -4},
    {NumberOfRoots::ONEROOT,    ComparisonStatus::EQUAL,        ComparisonStatus::UNKNOWN_CS,   4,    NAN,  0,  1,  -4,},
    {NumberOfRoots::NOROOTS,    ComparisonStatus::UNKNOWN_CS,   ComparisonStatus::UNKNOWN_CS,   NAN,  NAN,  0,  0,  1},
    {NumberOfRoots::INF_ROOTS,  ComparisonStatus::UNKNOWN_CS,   ComparisonStatus::UNKNOWN_CS,   NAN,  NAN,  0,  0,  0}
};

const struct TestsCalc test_quad[] = {
    {NumberOfRoots::NOROOTS,    ComparisonStatus::UNKNOWN_CS,   ComparisonStatus::UNKNOWN_CS,   NAN,    NAN,    1,  2,  3},
    {NumberOfRoots::ONEROOT,    ComparisonStatus::EQUAL,        ComparisonStatus::UNKNOWN_CS,   -1,     NAN,    1,  2,  1},
    {NumberOfRoots::TWOROOTS,   ComparisonStatus::EQUAL,        ComparisonStatus::EQUAL,        2,      3,      1,  -5, 6},
    {NumberOfRoots::ONEROOT,    ComparisonStatus::EQUAL,        ComparisonStatus::UNKNOWN_CS,   0,      NAN,    1,  0,  0},
    {NumberOfRoots::TWOROOTS,   ComparisonStatus::EQUAL,        ComparisonStatus::EQUAL,        -1,     0,      1,  1,  0}
};

const struct TestsOut test_output[] = {
    {"[no real roots]",             NumberOfRoots::NOROOTS,     NAN,    NAN},
    {"[root: 2]",                   NumberOfRoots::ONEROOT,     2.0,    NAN},
    {"[\nroots:\nx1: 1 x2: 2\n]",   NumberOfRoots::TWOROOTS,    1.0,    2.0},
    {"[inf roots]",                 NumberOfRoots::INF_ROOTS,   NAN,    NAN},
    {"[OUT default Nroots ERROR]",  NumberOfRoots::UNKNOWN_NR,  NAN,    NAN}
};

const size_t TEST_LIN_SIZE    = sizeof(test_lin)    / sizeof(test_lin[0]);
const size_t TEST_QUAD_SIZE   = sizeof(test_quad)   / sizeof(test_quad[0]);
const size_t TEST_OUTPUT_SIZE = sizeof(test_output) / sizeof(test_output[0]);


bool CalcCheck(struct tests_calc* obj);
bool OutCheck(struct tests_out* obj);
bool UnitTestCalcLin(void);
bool UnitTestCalcQuad(void);
bool UnitTestOutput(void);

#endif // _UNIT_TESTS_H_
