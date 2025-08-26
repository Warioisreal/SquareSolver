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
    ExecMode input_mode   = ExecMode::NORMAL;

    Parse_Exec(argc, argv, &input_mode);

    InputCoefficients(&a, &b, &c, input_mode);

    struct Coef_Roots obj_cr {a, b, c, &x1, &x2};

    n_roots = SolveGeneralQuadraticEquation(&obj_cr);

    OutputRootsOrError(n_roots, *obj_cr.root1, *obj_cr.root2);

    return 0;
}
