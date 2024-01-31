#include <stdio.h>

int main (void) {
  int ch;

  printf("Hello world!\n");
  while ((ch = getchar()) != EOF) {
    switch(ch) {
      case 'a':
      case 'A':
      case 'e':
      case 'E':
      case 'i':
      case 'I':
      case 'o':
      case 'O':
      case 'u':
      case 'U':
        putchar('*');
        break;
      default:
        putchar(ch);
    }
  }

  return 0;
}
