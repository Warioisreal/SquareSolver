#ifndef _ENUMNOR_H_
#define _ENUMNOR_H_

#define MAXLENSTRING 128

const double EPSILON = 1e-8;
const int COEFFICIENTSCOUNT = 3;

enum class NumberOfRoots : char {
    UNKNOWN_NR,
    NOROOTS,
    ONEROOT,
    TWOROOTS,
    INF_ROOTS
};

#endif // _ENUMNOR_H_
