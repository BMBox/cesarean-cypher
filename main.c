#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_LETTERS_IN_THE_ALPHABET 26

int rot13(void);

int aToDShift(void);

int decryptAToD(void);

int main(int argc, char **argv) {
  if (argc > 1) {
    // Check if the second argument is rot13 or not
    if (strcmp(argv[1], "-r") == 0) {
      rot13();
    } else if (strcmp(argv[1], "-d") == 0) {
      decryptAToD();
    } else {
      printf("Usage %s <-r|-d> \n", argv[0]);
      exit(EXIT_FAILURE);
    }
  } else {
    aToDShift();
  }
}

int aToDShift(void) {
  int shift, ch;

  shift = 'D' - 'A';

  while ((ch = getchar()) != EOF) {
    if (isalpha(ch)) {
      ch += shift;
      if ((ch > 'Z' && ch < 'a') || (ch > 'z')) {
        ch -= NUMBER_OF_LETTERS_IN_THE_ALPHABET;
      }
    }
    putchar(ch);
  }
  putchar('\n');
  return 0;
}

int decryptAToD(void) {
  int shift, ch;

  shift = 'A' - 'D';

  while ((ch = getchar()) != EOF) {
    if (isalpha(ch)) {
      ch += shift;
      if ('A' > ch || ('Z' < ch && ch < 'a')) {
        ch += NUMBER_OF_LETTERS_IN_THE_ALPHABET;
      }
    }
    putchar(ch);
  }
  putchar('\n');

  return 0;
}

int rot13(void) {
  int ch;

  while ((ch = getchar()) != EOF) {
    if (isalpha(ch)) {
      if (toupper(ch) >= 'A' && toupper(ch) <= 'M') {
        ch += 13;
      } else {
        ch -= 13;
      }
    }
    putchar(ch);
  }
  putchar('\n');

  return 0;
}
