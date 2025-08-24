#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "calculation.h"
#include "Unit_tests.h"
#include "Common.h"
#include "comp.h"
#include "Project_output.h"
#include "Project_input.h"


int main(int argc, char* argv[]) {

    NumberOfRoots n_roots = NumberOfRoots::UNKNOWN_NR;
    double a = 0.0, b = 0.0, c = 0.0, x1 = 0.0, x2 = 0.0;
    if ((argc > 1) && (strcmp(argv[1], "test") == 0)) {
        UnitTestCalcLin();
        UnitTestCalcQuad();
        UnitTestOutput();
    }

    InputCoefficients(&a, &b, &c);

    n_roots = SolveGeneralQuadraticEquation(a, b, c, &x1, &x2);

    OutputRootsOrError(n_roots, x1, x2);

    return 0;
}
