#include <stdio.h>

int main (void) {
  int ch;

  printf("Hello world!\n");
  while ((ch = getchar()) != EOF) {
    putchar(ch);
  }

  return 0;
}
