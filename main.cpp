#include <stdio.h>

#include "calculation.h"
#include "common.h"
#include "comp.h"
#include "handle_math.h"
#include "project_input.h"
#include "project_output.h"


int main(const int argc, const char* argv[]) {

    struct Equation obj_e = {NAN, NAN, NAN, NAN, NAN};

    NumberOfRoots n_roots = NumberOfRoots::UNKNOWN_NR;
    InteractionMode interaction_mode  = InteractionMode::NORMAL;

    Parse_Exec(argc, argv, &interaction_mode);

    InputCoefficients(&obj_e, interaction_mode);
    if (interaction_mode != InteractionMode::UNKNOWN) {

        n_roots = SolveGeneralQuadraticEquation(&obj_e);

        OutputRootsOrError(n_roots, obj_e.x1, obj_e.x2, interaction_mode);
    }
    return 0;
}
