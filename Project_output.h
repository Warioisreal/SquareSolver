#ifndef _PROJECT_OUTPUT_H_
#define _PROJECT_OUTPUT_H_

#include "common.h"
#include "handle_math.h"


void OutputRootsOrError(const NumberOfRoots n_roots, const double x1, const double x2, InteractionMode output_mode);
FILE* FileOutput(void);

#endif // _PROJECT_OUTPUT_H_
