#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}
int main() {
  int a = 0;
  int b = 10;

  swap(&a, &b);

  printf("a: %d, b: %d\n", a, b);
}
