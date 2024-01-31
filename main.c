#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (void) {
  int ch;
  srand ((unsigned) time (NULL));

  while ((ch = getchar()) != EOF) {
     // Randomize case of letters
      if (ch >= 'a' && ch <= 'z') {
        ch = rand() % 2 ? ch : ch - 32;
      } else if (ch >= 'A' && ch <= 'Z') {
        ch = rand() % 2 ? ch : ch + 32;
      }
      putchar(ch);
  }

  return 0;
}
