#include "../include/file_process.h"

void process_files(int file_names_length, int* file_names_indecies, char** argv,
                   int options[]) {
  for (int file_idx = 0; file_idx < file_names_length; file_idx++) {
    if (file_check(argv[file_names_indecies[file_idx]]) &&
        argv[file_names_indecies[file_idx]][0] != '-') {
      FILE* fp = fopen(argv[file_names_indecies[file_idx]], "r");
      if (!fp) {
        printf("custom_cat: %s: No such file or directory\n",
               argv[file_names_indecies[file_idx]]);
      } else {
        output_file(fp, options);
        fclose(fp);
      }
    } else if (argv[file_names_indecies[file_idx]][0] == '-' &&
               argv[file_names_indecies[file_idx]][1] == 0) {
      output_file(stdin, options);
    } else {
      printf("custom_cat: %s: Is a directory\n",
             argv[file_names_indecies[file_idx]]);
    }
  }
}

int file_check(char* name) {
  DIR* dir = opendir(name);
  int is_file = 1;
  if (dir) {
    closedir(dir);
    is_file = 0;
  }
  return is_file;
}

void output_file(FILE* fp, int options[]) {
  int blank_line_count = 0;
  int lines_count = 1;
  char prev_ch = '\n';
  int ch;

  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n') {
      blank_line_count++;
    } else {
      blank_line_count = 0;
    }

    if (options[OPT_S] == 1 && blank_line_count > 2 && ch == '\n') {
      continue;
    }

    if (prev_ch == '\n' &&
        (options[OPT_N] == 1 || (options[OPT_B] == 1 && ch != '\n'))) {
      if (options[OPT_B] == 1 && ch != '\n') {
        printf("%6d  ", lines_count);
        lines_count++;
      } else if (options[OPT_N] == 1 && options[OPT_B] != 1) {
        printf("%6d  ", lines_count);
        lines_count++;
      }
    }

    int printed = 0;
    if (options[OPT_E] == 1 && ch == '\n') {
      printf("$\n");
      printed = 1;
    }

    else if (options[OPT_V] == 1 || options[OPT_E] == 1 ||
             options[OPT_T] == 1) {
      if (ch == '\t' && options[OPT_T] == 1) {
        printf("^I");
        printed = 1;
      } else if ((ch >= 0 && ch <= 31) && ch != '\n' && ch != '\t') {
        printf("^%c", ch + 64);
        printed = 1;
      } else if (ch == 127) {
        printf("^?");
        printed = 1;
      }
    }

    if (!printed) printf("%c", ch);

    prev_ch = ch;
  }
}
