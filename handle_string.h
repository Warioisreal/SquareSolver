#ifndef _HANDLE_STRING_H_
#define _HANDLE_STRING_H_

#define MAX_LEN_STRING 128

static const char* DEFAULT_FILENAME_INPUT  = "input.txt";
static const char* DEFAULT_FILENAME_OUTPUT = "output.txt";

size_t CalcNumberCharInString(const char symbol, const char* string);
void FileName(char* filename, const char* mode);

#endif // _HANDLE_STRING_H_
