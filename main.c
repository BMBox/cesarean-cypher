#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void) {
  int ch;
  srand((unsigned) time(NULL));

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
