#include <stdio.h>
#include <assert.h>

#include "handle_string.h"
#include "project_input.h"
#include "special_commands.h"


void InputTerm(struct Equation* obj) {

    assert (obj != nullptr);

    double* const a = &(*obj).a_coef;
    double* const b = &(*obj).b_coef;
    double* const c = &(*obj).c_coef;

    int coef_count = 0;

    printf("\nenter equation coefficients: a [space] b [space] c [ax^2 + bx + c = 0]\n");

    while (coef_count != COEFFICIENTS_COUNT) {
        coef_count = scanf("%lg %lg %lg", a, b, c);
        bool check = Check(stdin);
        if ((coef_count == COEFFICIENTS_COUNT) && check) {
            printf("\ndata correct\n\n\\result/\n");
        } else {
            printf("\ndata incorrect, try enter data again\n"
                "\nenter equation coefficients: a [space] b [space] c [ax^2 + bx + c = 0]\n");
            coef_count = 0;
            CleanInput(stdin);
        }
    }
}


void InputFile(struct Equation* obj) {

    assert(obj != nullptr);

    double* const a = &(*obj).a_coef;
    double* const b = &(*obj).b_coef;
    double* const c = &(*obj).c_coef;

    char file_name[MAX_LEN_STRING] = "";
    FILE* file = nullptr;
    int coef_count = 0;

    printf("\nEnter input filename or press [enter] to skip\n");

    while (coef_count != COEFFICIENTS_COUNT) {

        FileName(file_name, DEFAULT_FILENAME_INPUT);

        file = fopen(file_name, "r");

        if (file == nullptr) {
            printf("read file error\n");
            break;
        } else {

            coef_count = fscanf(file, "%lg %lg %lg", a, b, c);

            bool check = Check(file);
            if ((coef_count == COEFFICIENTS_COUNT) && check) {
                printf("\ndata correct\n\n");
            } else {
                printf("\ndata incorrect, try enter filename again\n"
                    "\nEnter input filename or press [enter] to skip\n");
                coef_count = 0;
                CleanInput(file);
            }

            fclose(file);
        }
    }
}


void InputCoefficients(struct Equation* obj, const InteractionMode interaction_mode) {

    assert (obj != nullptr);

    if (interaction_mode == InteractionMode::NORMAL) {
        InputTerm(obj);
    } else if (interaction_mode == InteractionMode::FILE) {
        InputFile(obj);
    } else {
        printf("Input mode ERROR\n");
    }
}


void Parse_Exec(const int exec_size, const char* exec_data[], InteractionMode* input_mode) {
    if (exec_size == 1) {
        RunExecMode(ExecMode::NORMAL);
    } else {
        for (int i = 1; i < exec_size; i++) {
            for (size_t j = 0; j < LIST_MODE_SIZE; j++) {
                size_t minus_ct = CalcNumberCharInString('-', exec_data[i]);
                if ((minus_ct == 1 && strncmp(exec_data[i],  list_mode[j].exec_mode_short, MAX_LEN_STRING) == 0) ||
                    (minus_ct == 2 && strncmp(exec_data[i], list_mode[j].exec_mode_long, MAX_LEN_STRING) == 0)) {
                    if (!RunExecMode(static_cast<ExecMode>(j))) {
                        *input_mode = InteractionMode::UNKNOWN;
                    }
                    if (static_cast<ExecMode>(j) == ExecMode::FILE) {
                        *input_mode = InteractionMode::FILE;
                    }
                    break;
                }
                if (j + 1 == LIST_MODE_SIZE) {
                    *input_mode = InteractionMode::UNKNOWN;
                }
            }
        }
    }
}


bool RunExecMode(ExecMode instruction) {

    bool check_l = false;
    bool check_q = false;
    bool check_o = false;

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
            check_l = UnitTestCalcLin();
            check_q = UnitTestCalcQuad();
            check_o = UnitTestOutput();
            if ((check_l == false) || (check_q == false) || (check_o == false)) {
                return false;
            }
            break;
        case ExecMode::FILE: printf("\nfile input mode\n");
            break;
        case ExecMode::UNKNOWN: printf("\nexec mode ERROR\n");
            break;
        default: printf("\nRunExecMode switch ERROR\n");
    }
    return true;
}
