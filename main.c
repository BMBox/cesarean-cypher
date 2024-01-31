#include <stdio.h>

int main (void) {
  int ch;

  printf("Hello world!\n");
  while ((ch = getchar()) != EOF) {
    if (ch >= 'a' && ch <= 'z') {
      ch += ('A' - 'a');
      putchar(ch);
      continue;
    }
    putchar(ch);
  }

  return 0;
}
