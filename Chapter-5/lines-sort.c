// sorts a string of lines separated by \n
// used bubble sort instead of quicksort because quicksort is hard
#include <stdio.h>

#define MAX_LINES 100 // max num of lines
#define MAX_LINE 100  // max chars in line

void bubbleSort(char **);
void swapPointers(char **a, char **b);
void getPointerArray(char *linePointers[], char *st);
void getLine(char *p, char *lineTo);
int isLarger(char *cp1, char *cp2);

int main() {
  char strInput[] = "farst\narst\nparst\ncarst\nbarst\nah\nzarst\nfar";
  char currentLine[MAX_LINE];
  char *linePointers[MAX_LINES];

  getPointerArray(linePointers, strInput);
  bubbleSort(linePointers);

  for (int i = 0; linePointers[i]; i++) {
    getLine(linePointers[i], currentLine);
    printf("%s\n", currentLine);
  }
}

void bubbleSort(char **pointerArrStartpointer) {
  int sorted = 0;
  char **pointerArrPointer1, **pointerArrPointer2;

  if (**pointerArrStartpointer == '\0')
    return;

  while (!sorted) {
    sorted = 1;
    pointerArrPointer1 = pointerArrStartpointer;
    pointerArrPointer2 = pointerArrStartpointer + 1;
    while (*pointerArrPointer2) {
      if (isLarger(*pointerArrPointer1, *pointerArrPointer2)) {
        sorted = 0;
        swapPointers(pointerArrPointer1, pointerArrPointer2);
      }
      pointerArrPointer1++;
      pointerArrPointer2++;
    }
  }

  return;
}

int isLarger(char *cp1, char *cp2) {
  for (; *cp1 == *cp2; cp1++, cp2++) {
  }
  return *cp1 > *cp2;
}

void swapPointers(char **a, char **b) {
  char *temp = *a;
  *a = *b;
  *b = temp;
  return;
}

void getPointerArray(char **pointerArrayPointer, char *linesStringPointer) {
  if (!*linesStringPointer)
    return;
  *pointerArrayPointer++ = linesStringPointer;
  while (*linesStringPointer) {
    if (*linesStringPointer == '\n')
      *pointerArrayPointer++ = ++linesStringPointer;
    else
      linesStringPointer++;
  }
  return;
}

void getLine(char *p, char *lineTo) {
  for (; *p && *p != '\n'; p++, lineTo++) {
    *lineTo = *p;
  }
  *lineTo = '\0';
  return;
}
