#ifndef _CALCULATIONS_H_
#define _CALCULATIONS_H_

#include "common.h"

struct Coef_Roots {
    const double a_coef = 0.0;
    const double b_coef = 0.0;
    const double c_coef = 0.0;
    double* const root1 = nullptr;
    double* const root2 = nullptr;
};

NumberOfRoots SolveGeneralQuadraticEquation(struct Coef_Roots* obj);
NumberOfRoots LinearCalculator(struct Coef_Roots* obj);
NumberOfRoots QuadraticCalculator(struct Coef_Roots* obj);

#endif // _CALCULATIONS_H_
