#ifndef _SPECIAL_TERM_COMMANDS_H_
#define _SPECIAL_TERM_COMMANDS_H_

#include "common.h"

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

void CleanInputBuffer(void);

bool CheckBuffer(void);

void PrintSeparator(void);

void Parse_Exec(const int exec_size, const char* exec_data[], ExecMode* input_mode);

void RunExecMode(ExecMode mode);

#endif // _SPECIAL_TERM_COMMANDS_H_
