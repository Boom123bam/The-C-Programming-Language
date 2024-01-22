#include <stdbool.h>
#include <stdio.h>

// reduces multiple spaces in input to one

int main() {
    int c;
    bool prevWasSpace = 0;

    while ((c = getchar()) != '\n') {
        if (!(prevWasSpace && c == ' '))
            printf("%c", c);
        prevWasSpace = c == ' ';
    }
    printf("\n");
}
