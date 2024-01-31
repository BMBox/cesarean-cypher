#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


int main (void) {
  int ch;
  srand ((unsigned) time (NULL));

  while ((ch = getchar()) != EOF) {
     // Randomize case of letters
      if (rand() % 2) {
        putchar(toupper(ch));
      } else {
        putchar(tolower(ch));
      }
  }
  putchar('\n');

  return 0;
}
