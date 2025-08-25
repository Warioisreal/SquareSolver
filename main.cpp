#include <stdio.h>
#include <math.h>

#include "calculation.h"
#include "common.h"
#include "comp.h"
#include "project_output.h"
#include "project_input.h"
#include "special_term_commands.h"


int main(const int argc, const char* argv[]) {

    NumberOfRoots n_roots = NumberOfRoots::UNKNOWN_NR;
    double        a       = NAN;
    double        b       = NAN;
    double        c       = NAN;
    double        x1      = NAN;
    double        x2      = NAN;

    Parse_Exec(argc, argv);

    InputCoefficients(&a, &b, &c);

    n_roots = SolveGeneralQuadraticEquation(a, b, c, &x1, &x2);

    OutputRootsOrError(n_roots, x1, x2);

    return 0;
}
