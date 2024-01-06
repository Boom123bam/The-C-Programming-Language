#include <stdio.h>

#define MIN 0
#define MAX 200
#define STEP 20

float toCelcius(float fahr) { return (fahr - 32) * 5 / 9; }

int main() {
  for (float fahr = MIN; fahr <= MAX; fahr += STEP) {
    printf("%2.f%6.1f\n", fahr, toCelcius(fahr));
  }
  return 0;
}
