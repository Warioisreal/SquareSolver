#ifndef _HANDLE_MATH_H_
#define _HANDLE_MATH_H_

#include <math.h>

#include "comp.h"

static const double EPSILON = 1e-8;
static const int COEFFICIENTS_COUNT = 3;
/// Набор возможного количества корней квадратного уравнения
enum class NumberOfRoots : char {
    UNKNOWN_NR, ///< Указывает, что количество корней неопределенно
    NOROOTS, ///< Указывает, что уравнение не имеет действительных корней
    ONEROOT, ///< Указывает, что уравнение имеет 1 действительный корень
    TWOROOTS, ///< Указывает, что уравнение имеет 2 действительных корня
    INF_ROOTS ///< Указывает, что уравнение имеет бесконечно много решений
};

struct Equation {
    double a_coef = NAN;
    double b_coef = NAN;
    double c_coef = NAN;
    double x1 = NAN;
    double x2 = NAN;
};

#endif // _HANDLE_MATH_H_
