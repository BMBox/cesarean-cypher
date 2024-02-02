#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUMBER_OF_LETTERS_IN_THE_ALPHABET 26

void print_usage(char *program_name);

void shift_text(int shift, int direction);

void shift_text_with_offset(char offset, int modifier);

void rot13(void);

int main(int argc, char **argv) {
  if (argc < 2) {
    print_usage(argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "-rot") == 0) {
    rot13();
  } else if (isalpha(*argv[1])) {
    int modifier = argc > 2 && strcmp(argv[2], "-d") == 0;
    shift_text_with_offset(*argv[1], modifier);
  } else {
    print_usage(argv[0]);
    return 1;
  }

  return 0;
}

void print_usage(char *program_name) {
  printf("Usage: %s <-rot| offset{a-z|A-Z}> [modifier{-d}]\n", program_name);
}

void shift_text(int shift, int direction) {
  int ch;

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

void shift_text_with_offset(char offset, int modifier) {
  int shift = modifier == 1 ? 'A' - toupper(offset) : toupper(offset) - 'A';
  int direction = modifier == 1 ? 1 : -1;
  shift_text(shift, direction);
}

void rot13(void) {
  shift_text(13, 1);
}
