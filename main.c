#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUMBER_OF_LETTERS_IN_THE_ALPHABET 26
#define ROT13_SHIFT 13

void print_usage(char *program_name);

void shift_text(char offset, int modifier, int default_shift);

int main(const int argc, char **argv) {
  if (argc < 2) {
    print_usage(argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "-rot") == 0) {
    shift_text(0, 0, ROT13_SHIFT);
  } else if (isalpha(*argv[1])) {
    const int modifier = argc > 2 && strcmp(argv[2], "-d") == 0;
    shift_text(*argv[1], modifier, 0);
  } else {
    print_usage(argv[0]);
    return 1;
  }

  return 0;
}

void print_usage(char *program_name) {
  printf("Usage: %s <-rot| offset{a-z|A-Z}> [modifier{-d}]\n", program_name);
}

void shift_text(char offset, int modifier, int default_shift) {
  int ch;
  int shift = default_shift;
  if (offset != 0) {
    shift = modifier == 1 ? 'A' - toupper(offset) : toupper(offset) - 'A';
  }
  int direction = modifier == 1 ? 1 : -1;

  int trim_out_of_bounds = NUMBER_OF_LETTERS_IN_THE_ALPHABET * direction;
  while ((ch = getchar()) != EOF) {
    if (isalpha(ch)) {
      ch += shift;
      if ((ch <= 'A') || (ch > 'Z' && ch < 'a') || ch > 'z') {
        ch += trim_out_of_bounds;
      }
    }
    putchar(ch);
  }
  putchar('\n');
}

