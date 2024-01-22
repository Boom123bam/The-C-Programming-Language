#include <stdio.h>

int main() {
    int numSpace, numOthers, c;
    numSpace = numOthers = 0;
    int nums[10];

    for (int i = 0; i < 10; i++) {
        nums[i] = 0;
    }
    while ((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            nums[c - '0']++;
        } else if (c == ' ' || c == '\t') {
            numSpace++;
        } else {
            numOthers++;
        }
    }

    printf("number: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }
    printf("\nothers: %d\nspaces: %d\n", numOthers, numSpace);
    return 0;
}
