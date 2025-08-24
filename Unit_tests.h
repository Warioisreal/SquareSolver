#ifndef _UNIT_TESTS_H_
#define _UNIT_TESTS_H_

#include <string.h>

#include "Common.h"
#include "comp.h"


int UnitTestCalcLin(void);
int UnitTestCalcQuad(void);
int UnitTestOutput(void);
bool CalcCheck(const NumberOfRoots ct_root, const ComparisonStatus cmp1, const ComparisonStatus cmp2,
            const double res1, const double res2, const double a, const double b, const double c);
bool OutCheck(const char* cmd, const NumberOfRoots ct_root, const double res1, const double res2);

#endif // _UNIT_TESTS_H_
