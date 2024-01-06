#include <stdio.h>

#define MAXLINE 100

void copy();

int currentLen = 0;
char maxLine[MAXLINE], currentLine[MAXLINE];

int main() {
  int maxLen = 0;
  char currentChar;

  extern int currentLen;
  extern char maxLine[], currentLine[];

  while ((currentChar = getchar()) != '.') {
    if (currentChar == '\n') {
      if (currentLen > maxLen) {
        currentLine[currentChar] = '\0';
        maxLen = currentLen;

        copy();
      }
      currentLen = 0;
    } else {
      currentLine[currentLen] = currentChar;
      currentLen++;
    }
  }

  printf("longest: %s\nlength: %d\n", maxLine, maxLen);

  return 0;
}

void copy() {
  int i = 0;
  extern char maxLine[], currentLine[];
  do {
    maxLine[i] = currentLine[i];
    i++;
  } while (currentLine[i] != '\0');
}
