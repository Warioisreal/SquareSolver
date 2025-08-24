#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "unit_tests.h"
#include "project_output.h"
#include "calculation.h"
#include "comp.h"
#include "common.h"
#include "buff_clear.h"


bool CalcCheck(struct tests_calc obj) {

    const NumberOfRoots ct_root = obj.nor;
    const ComparisonStatus cmp1 = obj.cs1, cmp2 = obj.cs2;
    const double res1 = obj.result1, res2 = obj.result2, a = obj.a_coef, b = obj.b_coef, c = obj.c_coef;

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


bool OutCheck(struct tests_out obj) {

    const char*         cmd     = obj.command;
    const NumberOfRoots ct_root = obj.count_root;
    const double        res1    = obj.result1, res2 = obj.result2;

    assert (cmd != nullptr);

    char ent = '\t';
    printf("\nis output: %s ? | y - yes | n - no\n", cmd);
    Separator();
    OutputRootsOrError(ct_root, res1, res2);
    Separator();
    scanf("%c", &ent);

    Cleaner();

    return ent == 'y';
}


int UnitTestCalcLin(void) {
    struct tests_calc test_lin[] = {
        {NumberOfRoots::ONEROOT, ComparisonStatus::EQUAL, ComparisonStatus::UNKNOWN_CS, 2, NAN, 0, 2, -4},
        {NumberOfRoots::ONEROOT, ComparisonStatus::EQUAL, ComparisonStatus::UNKNOWN_CS, 4, NAN, 0, 1, -4,},
        {NumberOfRoots::NOROOTS, ComparisonStatus::UNKNOWN_CS, ComparisonStatus::UNKNOWN_CS, NAN, NAN, 0, 0, 1},
        {NumberOfRoots::INF_ROOTS, ComparisonStatus::UNKNOWN_CS, ComparisonStatus::UNKNOWN_CS, NAN, NAN, 0, 0, 0}
    };

    for (int i = 0; i < 4; i++) {
        if (!CalcCheck(test_lin[i])) {
            printf("%dL\n", i + 1);
            break;
        }
        if (i == 4) {
            printf("\n>>CalcLin correct<<\n");
        }
    }

    return 0;
}


int UnitTestCalcQuad(void) {

    struct tests_calc test_quad[] = {
        {NumberOfRoots::NOROOTS, ComparisonStatus::UNKNOWN_CS, ComparisonStatus::UNKNOWN_CS, NAN, NAN, 1, 2, 3},
        {NumberOfRoots::ONEROOT, ComparisonStatus::EQUAL, ComparisonStatus::UNKNOWN_CS, -1, NAN, 1, 2, 1},
        {NumberOfRoots::TWOROOTS, ComparisonStatus::EQUAL, ComparisonStatus::EQUAL, 2, 3, 1, -5, 6},
        {NumberOfRoots::ONEROOT, ComparisonStatus::EQUAL, ComparisonStatus::UNKNOWN_CS, 0, NAN, 1, 0, 0},
        {NumberOfRoots::TWOROOTS, ComparisonStatus::EQUAL, ComparisonStatus::EQUAL, -1, 0, 1, 1, 0}
    };

    for (int i = 0; i < 5; i++) {
        if (!CalcCheck(test_quad[i])) {
            printf("%dL\n", i + 1);
            break;
        }
        if (i == 5) {
            printf("\n>>CalcQuad correct<<\n");
        }
    }

    return 0;
}


int UnitTestOutput(void) {

    struct tests_out test_output[] = {
        {"[no real roots]", NumberOfRoots::NOROOTS, NAN, 0},
        {"[root: 2]", NumberOfRoots::ONEROOT, 2.0, 0},
        {"[\nroots:\nx1: 1 x2: 2\n]", NumberOfRoots::TWOROOTS, 1.0, 2.0},
        {"[inf roots]", NumberOfRoots::INF_ROOTS, 0, 0},
        {"[OUT default Nroots ERROR]", NumberOfRoots::UNKNOWN_NR, 0, 0}
    };

    for (int i = 0; i < 5; i++) {
        if (!OutCheck(test_output[i])) {
            printf("%dL\n", i + 1);
            break;
        }
        if (i == 5) {
            printf("\n>>Output correct<<\n");
        }
    }

    return 0;
}
