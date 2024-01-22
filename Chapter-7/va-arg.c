#include <stdarg.h>
#include <stdio.h>

int sum(int base, ...);

int main() { printf("%d\n", sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10)); }

int sum(int num_nums, ...) {
    va_list numsp;
    int sum = 0;
    va_start(numsp, num_nums);
    for (int i = 0; i < num_nums; i++) {
        sum += va_arg(numsp, int);
    }
    return sum;
}
