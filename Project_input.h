#ifndef _PROJECT_INPUT_H_
#define _PROJECT_INPUT_H_

#include "special_term_commands.h"

void InputCoefficients(double* a, double* b, double* c, const ExecMode mode);
void InputTerm(double* a, double* b, double* c);
void InputFile(double* a, double* b, double* c);

#endif // _PROJECT_INPUT_H_
