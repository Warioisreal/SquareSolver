#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "calculation.h"
#include "common.h"
#include "comp.h"
#include "project_output.h"
#include "special_commands.h"
#include "unit_tests.h"


bool CalcCheck(const struct TestsCalc* obj) {

    assert (obj != nullptr);

    const NumberOfRoots ct_root     = (*obj).nor;
    const ComparisonStatus cmp1     = (*obj).cs1;
    const ComparisonStatus cmp2     = (*obj).cs2;
    const double        res1        = (*obj).result1;
    const double        res2        = (*obj).result2;

    struct Equation obj_e {(*obj).a_coef, (*obj).b_coef, (*obj).c_coef, NAN, NAN};

    assert (isfinite(obj_e.a_coef));
    assert (isfinite(obj_e.b_coef));
    assert (isfinite(obj_e.c_coef));

    bool ct = true;
    ct = (ct && (SolveGeneralQuadraticEquation(&obj_e) == ct_root));

    switch (ct_root) {
        case NumberOfRoots::ONEROOT:
            ct = (ct && (ComparisonNumb(obj_e.x1, res1) == cmp1));
            break;
        case NumberOfRoots::TWOROOTS:
            ct = (ct && (ComparisonNumb(obj_e.x1, res1) == cmp1));
            ct = (ct && (ComparisonNumb(obj_e.x2, res2) == cmp2));
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
    printf("\nis output: %s ?   y - yes | n - no\n", cmd);
    PrintSeparator();
    OutputRootsOrError(ct_root, res1, res2, InteractionMode::NORMAL);
    PrintSeparator();
    scanf("%c", &answer);

    return (answer == 'y') && Check(stdin);
}


bool UnitTestCalcLin(void) {

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
        return true;
    } else {
        printf("%zuL\n", pass_tests + 1);
        return false;
    }
}


bool UnitTestCalcQuad(void) {

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
        return true;
    } else {
        printf("%zuQ\n", pass_tests + 1);
        return false;
    }
}


bool UnitTestOutput(void) {

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
        return true;
    } else {
        printf("%zuL\n", pass_tests + 1);
        return false;
    }
}
