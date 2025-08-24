#ifndef _UNIT_TESTS_H_
#define _UNIT_TESTS_H_

#include <string.h>

#include "common.h"
#include "comp.h"


int UnitTestCalcLin(void);
int UnitTestCalcQuad(void);
int UnitTestOutput(void);
bool CalcCheck(struct tests_calc obj);
bool OutCheck(struct tests_out obj);

#endif // _UNIT_TESTS_H_
