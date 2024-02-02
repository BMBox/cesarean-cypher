#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_LETTERS_IN_THE_ALPHABET 26

int rot13(void);

int aToDShift(void);

int decryptAToD(void);

int cypher(int offset, int modifier);

int main(int argc, char **argv) {
  if (argc > 2) {
    int modifier = strcmp(argv[2], "-d") == 0;
    if (isalpha(*argv[1]) && modifier == 1) {
      cypher(*argv[1], modifier);
    } else {
      printf("Usage: %s <-rot|-decr| offset{a-z|A-Z}> <modifier{-d}>", argv[0]);
    }
  } else if (argc > 1) {
    if (strcmp(argv[1], "-rot") == 0) {
      rot13();
    } else if (strcmp(argv[1], "-decr") == 0) {
      decryptAToD();
    } else if (isalpha(*argv[1])) {
      cypher((*argv[1]), 0);
    } else {
      printf("Usage: %s <-rot|-decr|{a-z|A-Z}", argv[0]);
    }

  } else {
    aToDShift();
  }
  return 0;
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


int cypher(int offset, int modifier) {
  int ch;
  int shift = modifier == 1 ? 'A' - toupper(offset) : toupper(offset) - 'A';

  while ((ch = getchar()) != EOF) {
    if (isupper(ch)) {
      ch += shift;
      if (ch > 'Z') ch -= NUMBER_OF_LETTERS_IN_THE_ALPHABET;
      if (ch < 'A') ch += NUMBER_OF_LETTERS_IN_THE_ALPHABET;
      putchar(ch);
    } else if (islower(ch)) {
      ch += shift;
      if (ch > 'z') ch -= NUMBER_OF_LETTERS_IN_THE_ALPHABET;
      if (ch < 'a') ch += NUMBER_OF_LETTERS_IN_THE_ALPHABET;
      putchar(ch);
    } else {
      putchar(ch);
    }
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
