#include <stdio.h>
#include <string.h>

#include "unit_tests.h"
#include "special_term_commands.h"


int CleanInputBuffer(void) {

    while (getchar() != '\n') {
        continue;
    }

    return 0;
}


int PrintSeparator(void) {
    printf("-------------------\n");
    return 0;
}


int Parse_Exec(const int exec_size, const char* exec_data[]) {

    if (exec_size == 1) {
        RunExecMode(ExecMode::NORMAL);
    } else {
        for (int i = 1; i < exec_size; i++) {
            for (size_t j = 0; j < LIST_MODE_SIZE; j++) {
                if (strncmp(exec_data[i], list_mode[j].exec_mode_long, MAX_LEN_STRING) == 0 ||
                    strncmp(exec_data[i], list_mode[j].exec_mode_short, MAX_LEN_STRING) == 0) {
                    RunExecMode(static_cast<ExecMode>(j));
                }
            }
        }
    }

    return 0;
}


int RunExecMode(ExecMode instruction) {
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
        case ExecMode::FILE: printf("file mode\n");
            break;
        case ExecMode::UNKNOWN: printf("exec mode ERROR\n");
            break;
        default: printf("RunExecMode switch ERROR\n");
    }

    return 0;
}
