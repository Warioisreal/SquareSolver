#include <assert.h>
#include <math.h>

#include "comp.h"
#include "handle_math.h"


ComparisonStatus ComparisonNumb(const double val1, const double val2) {

    assert (isfinite (val1));
    assert (isfinite (val2));

    ComparisonStatus s_o_z = ComparisonStatus::UNKNOWN_CS;
    if (val1 - val2 > EPSILON) {
        s_o_z = ComparisonStatus::FIRST;
    } else if (val1 - val2 < -EPSILON) {
        s_o_z = ComparisonStatus::SECOND;
    } else {
        s_o_z = ComparisonStatus::EQUAL;
    }
    return s_o_z;
}
