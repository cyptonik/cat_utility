#include "../headers/options.h"

int resize_file_names(int** file_names_indecies, int* file_names_cap) {
  int temp_cap = (*file_names_cap) * 2;
  int fail = 0;
  int* temp = (int*)realloc(*file_names_indecies, temp_cap * sizeof(int));
  if (temp) {
    *file_names_indecies = temp;
    *file_names_cap = temp_cap;
  } else {
    fprintf(stderr,
            "custom_cat: fatal: Failed to allocate memory for file list.\n");
    fail = 1;
  }
  return fail;
}

int get_options(char* option_name, int options[]) {
  int fail = 0;
  if (strcmp(option_name, "-b") == 0 ||
      strcmp(option_name, "--number-nonblank") == 0)
    options[OPT_B] = 1;
  else if (strcmp(option_name, "-e") == 0)
    options[OPT_E] = 1;
  else if (strcmp(option_name, "-n") == 0 ||
           strcmp(option_name, "--number") == 0)
    options[OPT_N] = 1;
  else if (strcmp(option_name, "-s") == 0 ||
           strcmp(option_name, "--squeeze-blank") == 0)
    options[OPT_S] = 1;
  else if (strcmp(option_name, "-t") == 0)
    options[OPT_T] = 1;
  else if (strcmp(option_name, "-v") == 0)
    options[OPT_V] = 1;
  else
    fail = 1;

  return fail;
}
