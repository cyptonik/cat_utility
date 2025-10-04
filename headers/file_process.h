#ifndef FILE_PROCESS_H

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "options.h"

#define FILE_PROCESS_H

int file_check(char* name);
void output_file(FILE* fp, int options[]);
void process_files(int file_names_length, int* file_names_indecies, char** argv,
                   int options[]);

#endif
