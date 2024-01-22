#include <stdio.h>

void strcat2(char *st1, char *st2) {
    for (; *st1; st1++) {
    }
    for (; (*st1 = *st2); st1++, st2++) {
    }
}

// returns 1 if st2 is at the end of st1, 0 otherwise
int strend(char *st1, char *st2) {
    for (; *st1; st1++) {
    }
    for (; *st2; st2++) {
    }
    for (; *st2 == *st1; st1--, st2--) {
    }
    return *st2 ? 0 : 1;
}

int main() {
    char st1[10] = "amo";
    char st2[] = "gus";

    printf("%d\n", strend(st1, st2));
    strcat2(st1, st2);
    printf("%d\n", strend(st1, st2));
    printf("%s\n", st1);
    printf("%d\n", strend("hello bogus", "us"));
    printf("%d\n", strend("hello bogus", "gu"));
}
