/*
 * reverse polish calculator
 */

#include "./stack.h"
#include <stdio.h>

#define MAX_INPUT 100

char getNext(char input[]) {
    static int currentIndex = 0;
    char c;

    while ((c = input[currentIndex++]) == ' ' || c == '\t') {
    }

    return c;
}

int main() {
    char input[MAX_INPUT] = "1 2 - 3 4 + *"; // result: -7
    char c;
    int op2;

    while ((c = getNext(input)) != '\0') {
        if (c >= '0' && c <= '9') {
            push(c - '0');
            continue;
        }

        switch (c) {
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0)
                push(pop() / op2);
            else
                printf("division by 0 error\n");
            break;
        }
    }

    printf("result: %d\n", pop());
}
