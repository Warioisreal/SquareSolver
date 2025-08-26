#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "unit_tests.h"
#include "special_term_commands.h"


bool CheckBuffer(void) {

    bool result = true;

    while (getchar() != '\n') {
        result = result && isspace(getchar());
    }

    return result;
}


void CleanInputBuffer(void) {
    while (getchar() != '\n') {
        continue;
    }
}


void PrintSeparator(void) {
    printf("-------------------\n");
}


void Parse_Exec(const int exec_size, const char* exec_data[], ExecMode* input_mode) {
    printf("%d\n", CalcNumberCharInString('-', "--help"));
    if (exec_size == 1) {
        RunExecMode(ExecMode::NORMAL);
    } else {
        for (int i = 1; i < exec_size; i++) {
            for (size_t j = 0; j < LIST_MODE_SIZE; j++) {
                if ((CalcNumberCharInString('-', exec_data[i]) == 1 && strncmp(exec_data[i],  list_mode[j].exec_mode_long, MAX_LEN_STRING) == 0) ||
                    (CalcNumberCharInString('-', exec_data[i]) == 2 && strncmp(exec_data[i], list_mode[j].exec_mode_short, MAX_LEN_STRING) == 0)) {
                    RunExecMode(static_cast<ExecMode>(j));
                    if (static_cast<ExecMode>(j) == ExecMode::FILE) {
                        *input_mode = ExecMode::FILE;
                    }
                    break;
                }
                if (j + 1 == LIST_MODE_SIZE) {
                    RunExecMode(ExecMode::UNKNOWN);
                }
            }
        }
    }
}


void RunExecMode(ExecMode instruction) {
    switch (instruction) {
        case ExecMode::NORMAL:
            break;
        case ExecMode::HELP:
            printf("\navailable operating mode:\n");
            for (size_t i = 0; i < LIST_MODE_SIZE; i++) {
                printf("%zu) %s", i + 1, list_mode[i].description);
            }
            break;
        case ExecMode::TEST:
            UnitTestCalcLin();
            UnitTestCalcQuad();
            UnitTestOutput();
            break;
        case ExecMode::FILE: printf("\nfile input mode\n");
            break;
        case ExecMode::UNKNOWN: printf("\nexec mode ERROR\n");
            break;
        default: printf("\nRunExecMode switch ERROR\n");
    }
}
