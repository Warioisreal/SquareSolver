#ifndef _COMP_H_
#define _COMP_H_

enum class ComparisonStatus : char {
    UNKNOWN_CS,
    FIRST,
    EQUAL,
    SECOND
};


ComparisonStatus ComparisonNumb(const double val1, const double val2);

#endif // _COMP_H_
