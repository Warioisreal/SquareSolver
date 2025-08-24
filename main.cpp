#include <stdio.h>
#include <math.h>

#include "calculation.h"
#include "unit_tests.h"
#include "common.h"
#include "comp.h"
#include "project_output.h"
#include "project_input.h"


int main(int argc, char* argv[]) {

    NumberOfRoots n_roots = NumberOfRoots::UNKNOWN_NR;
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    if ((argc > 1) && (strcmp(argv[1], "--test") == 0)) {
        UnitTestCalcLin();
        UnitTestCalcQuad();
        UnitTestOutput();
    }

    InputCoefficients(&a, &b, &c);

    n_roots = SolveGeneralQuadraticEquation(a, b, c, &x1, &x2);

    OutputRootsOrError(n_roots, x1, x2);

    return 0;
}
