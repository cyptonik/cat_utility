#include "headers/file_process.h"
#include "headers/options.h"

int main(int argc, char** argv) {
  int options[SIZE] = {0};

  int file_names_length = 0;
  int file_names_cap = CAPACITY;
  int* file_names_indecies = (int*)malloc(file_names_cap * sizeof(int));

  int fail = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && argv[i][1] != 0) {
      if (get_options(argv[i], options) != 0) fail = i;
    } else {
      file_names_indecies[file_names_length++] = i;
      if (file_names_length >= file_names_cap)
        fail = resize_file_names(&file_names_indecies, &file_names_cap);
    }
  }

  if (file_names_length == 0 && fail == 0) {
    output_file(stdin, options);
  } else if (fail != 0) {
    printf("custom_cat: invalid option -- '%c'\n", argv[fail][1]);
  } else {
    process_files(file_names_length, file_names_indecies, argv, options);
  }

  free(file_names_indecies);

  return fail;
}
