#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_process.h"

#define CAPACITY 10
typedef enum { OPT_B, OPT_E, OPT_N, OPT_S, OPT_T, OPT_V, SIZE } OPTS;
int get_options(char* option_name, int options[]);
int resize_file_names(int** file_names_indecies, int* file_names_cap);

#endif
