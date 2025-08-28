#ifndef _PROJECT_INPUT_H_
#define _PROJECT_INPUT_H_

#include "common.h"
#include "handle_math.h"
#include "unit_tests.h"

enum class ExecMode : char {
    TEST    = 0,
    HELP    = 1,
    FILE    = 2,
    NORMAL  = 3,
    UNKNOWN = 4
};

struct ExecToMode {
    char exec_mode_long[MAX_LEN_STRING]  = "";
    char exec_mode_short[MAX_LEN_STRING] = "";
    char description[MAX_LEN_STRING]     = "";
};

const struct ExecToMode list_mode[] = {
    {"--test",   "-t", "--test OR -t  ->  [run functions tests and print results\n"},
    {"--help",   "-h", "--help OR -h  ->  [print all available operating mode]\n"},
    {"--file",   "-f", "--file OR -f  ->  [input data from file]\n"},
    {      "",     "", "              ->  [run base mode]\n"}
};

const size_t LIST_MODE_SIZE = sizeof(list_mode) / sizeof(list_mode[0]);


void InputTerm(struct Equation* obj);
void InputFile(struct Equation* obj);
void InputCoefficients(struct Equation* obj, const InteractionMode interaction_mode);
void Parse_Exec(const int exec_size, const char* exec_data[], InteractionMode* input_mode);
bool RunExecMode(ExecMode instruction);

#endif // _PROJECT_INPUT_H_
