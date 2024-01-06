#include <stdio.h>

int main() {
  int c;
  long count = 0;
  while ((c = getchar()) != EOF) {
    ++count;
    printf("%ld\n", count);
  }
  return 0;
}
