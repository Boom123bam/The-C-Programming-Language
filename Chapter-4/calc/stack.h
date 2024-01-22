#include <stdio.h>

#define MAX_STACK 100

static int stack[MAX_STACK];
static int stackSize = 0;

void push(int num) {
    if (stackSize < MAX_STACK - 1)
        stack[stackSize++] = num;
    else
        printf("error: stack full");
}

int pop() {
    if (stackSize > 0)
        return stack[--stackSize];

    printf("error: can't pop from empty stack");
    return '\0';
}

void printStack() {
    for (int i = 0; i < stackSize;) {
        printf("%d ", stack[i++]);
    }
    printf("\n");
}
