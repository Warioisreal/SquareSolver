#ifndef _CALCULATIONS_H_
#define _CALCULATIONS_H_

#include "common.h"


NumberOfRoots SolveGeneralQuadraticEquation(const double a, const double b, const double c, double* const x1, double* const x2);
NumberOfRoots LinearCalculator(const double b, const double c, double* const x1);
NumberOfRoots QuadraticCalculator(const double a, const double b, const double c, double* const x1, double* const x2);

#endif // _CALCULATIONS_H_
