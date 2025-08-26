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

    double x1 = NAN, x2 = NAN;

    struct Coef_Roots obj_cr {(*obj).a_coef, (*obj).b_coef, (*obj).c_coef, &x1, &x2};

    assert (isfinite(obj_cr.a_coef));
    assert (isfinite(obj_cr.b_coef));
    assert (isfinite(obj_cr.c_coef));

    bool ct = true;
    ct = (ct && (SolveGeneralQuadraticEquation(&obj_cr) == ct_root));

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

    return (answer == 'y') && CheckBuffer();
}


void UnitTestCalcLin(void) {

    size_t pass_tests = 0;

    for (size_t i = 0; i < TEST_LIN_SIZE; i++) {
        if (CalcCheck(&test_lin[i])) {
            pass_tests++;
        } else {
            break;
        }
    }
    if (pass_tests == TEST_LIN_SIZE) {
        printf("\n>>CalcLin correct<<\n");
    } else {
        printf("%zuL\n", pass_tests + 1);
    }
}


void UnitTestCalcQuad(void) {

    size_t pass_tests = 0;

    for (size_t i = 0; i < TEST_QUAD_SIZE; i++) {
        if (CalcCheck(&test_quad[i])) {
            pass_tests++;
        } else {
            break;
        }
    }
    if (pass_tests == TEST_QUAD_SIZE) {
        printf("\n>>CalcQuad correct<<\n");
    } else {
        printf("%zuQ\n", pass_tests + 1);
    }
}


void UnitTestOutput(void) {

    size_t pass_tests = 0;

    for (size_t i = 0; i < TEST_OUTPUT_SIZE; i++) {
        if (OutCheck(&test_output[i])) {
            pass_tests++;
        } else {
            break;
        }
    }
    if (pass_tests == TEST_OUTPUT_SIZE) {
        printf("\n>>Output correct<<\n");
    } else {
        printf("%zuL\n", pass_tests + 1);
    }
}
