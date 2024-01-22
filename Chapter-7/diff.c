#include <stdio.h>
#include <string.h>

#define MAX_LINE 100

int main() {
    FILE *f1p, *f2p;
    char line1[MAX_LINE], line2[MAX_LINE];
    int line_num = 0;

    f1p = fopen("Chapter-6/1.txt", "r");
    f2p = fopen("Chapter-6/2.txt", "r");

    if (f1p == NULL) {
        printf("could not open file 1\n");
        return -1;
    }
    if (f2p == NULL) {
        printf("could not open file 2\n");
        return -1;
    }

    do {
        fgets(line1, MAX_LINE, f1p);
        fgets(line2, MAX_LINE, f2p);
        line_num++;
    } while (strcmp(line1, line2) == 0);

    printf("first diff at line %d.\nfile1: %sfile2: %s", line_num, line1,
           line2);
}
