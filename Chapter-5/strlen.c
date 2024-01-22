#include <stdio.h>

int strlen2(char *c);
int strlen3(char *c);

int main() {
    char string[] = "hello world";

    printf("length: %d\n", strlen3(string));
}

int strlen2(char *c) {
    int i;
    for (i = 0; *(c + i) != '\0'; i++) {
    }
    return i;
}

int strlen3(char *c) {
    int i;
    for (i = 0; *c != '\0'; i++, c++) {
    }
    return i;
}
