#include <stdio.h>

void filter(int *numPtr, int numsLen, int (*filterFunc)(int)) {
    for (int i = 0; i < numsLen; i++, numPtr++) {
        if ((*filterFunc)(*numPtr))
            printf("%d ", *numPtr);
    }
}

int filterFunc(int num) { return num > 100; }

int main() {
    int nums[10] = {64, 38, 189, 54, 942, 853, 83, 340, 64, 56};

    filter(nums, 10, filterFunc);
    printf("\n");
}
