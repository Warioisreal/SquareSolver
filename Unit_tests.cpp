#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "unit_tests.h"
#include "project_output.h"
#include "calculation.h"
#include "comp.h"
#include "common.h"
#include "special_term_commands.h"


bool CalcCheck(const struct TestsCalc* obj) {

    assert (obj != nullptr);

    const NumberOfRoots ct_root     = (*obj).nor;
    const ComparisonStatus cmp1     = (*obj).cs1;
    const ComparisonStatus cmp2     = (*obj).cs2;
    const double        res1        = (*obj).result1;
    const double        res2        = (*obj).result2;
    const double         a          = (*obj).a_coef;
    const double         b          = (*obj).b_coef;
    const double         c          = (*obj).c_coef;

    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    bool ct = true;
    double x1 = NAN, x2 = NAN;

    ct = (ct && (SolveGeneralQuadraticEquation(a, b, c, &x1, &x2) == ct_root));

    switch (ct_root) {
        case NumberOfRoots::ONEROOT:
            ct = (ct && (ComparisonNumb(x1, res1) == cmp1));
            break;
        case NumberOfRoots::TWOROOTS:
            ct = (ct && (ComparisonNumb(x1, res1) == cmp1));
            ct = (ct && (ComparisonNumb(x2, res2) == cmp2));
            break;
        case NumberOfRoots::UNKNOWN_NR:
        case NumberOfRoots::NOROOTS:
        case NumberOfRoots::INF_ROOTS: break;
        default: printf("CalcCheck switch ERROR\n");
    }

    return ct;
}


bool OutCheck(const struct TestsOut* obj) {

    assert (obj != nullptr);

    const char*         cmd     = (*obj).command;
    const NumberOfRoots ct_root = (*obj).count_root;
    const double        res1    = (*obj).result1;
    const double        res2    = (*obj).result2;

    assert (cmd != nullptr);

    char answer = '\t';
    printf("\nis output: %s ? | y - yes | n - no\n", cmd);
    PrintSeparator();
    OutputRootsOrError(ct_root, res1, res2);
    PrintSeparator();
    scanf("%c", &answer);

    CleanInputBuffer();

    return answer == 'y';
}


int UnitTestCalcLin(void) {

    for (size_t i = 0; i < TEST_LIN_SIZE; i++) {
        if (!CalcCheck(&test_lin[i])) {
            printf("%zuL\n", i + 1);
            break;
        }
        if (i + 1 == TEST_LIN_SIZE) {
            printf("\n>>CalcLin correct<<\n");
        }
    }

    return 0;
}


int UnitTestCalcQuad(void) {

    for (size_t i = 0; i < TEST_QUAD_SIZE; i++) { // sizeof
        if (!CalcCheck(&test_quad[i])) {
            printf("%zuL\n", i + 1);
            break;
        }
        if (i + 1 == TEST_QUAD_SIZE) {
            printf("\n>>CalcQuad correct<<\n");
        }
    }

    return 0;
}


int UnitTestOutput(void) {

    for (size_t i = 0; i < TEST_OUTPUT_SIZE; i++) {
        if (!OutCheck(&test_output[i])) {
            printf("%zuL\n", i + 1);
            break;
        }
        if (i + 1 == TEST_OUTPUT_SIZE) {
            printf("\n>>Output correct<<\n");
        }
    }

    return 0;
}
