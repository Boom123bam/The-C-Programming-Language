/*
 * Read input lines until blank line entered
 *
 * Print the lines that contain the string to find
*/

#include <stdio.h>
#include <string.h>

#define MAX_LINE 50
#define MAX_LINES 10
#define STRING_TO_FIND "ough"

int getLine(char to[], int maxLen);
int getIndex(char src[], char strToFind[], int maxLen);

int main(){
  char currentLine[MAX_LINE];
  char lines[MAX_LINE][MAX_LINES];

  int i, y;
  i = y = 0;

  while (getLine(currentLine, MAX_LINE) > 0 ){
    if (getIndex(currentLine, STRING_TO_FIND, MAX_LINE) != -1) {
      strcpy(lines[i++], currentLine);
    }
  }

  while (y < i)
    printf("%s\n", lines[y++]);

  return 0;
}

int getLine(char to[], int maxLen){
  char c;
  int i = 0;

  while ((scanf("%c", &c)) && c != '\n' && i < maxLen) {
    to[i++] = c;
  }
  to[i] = '\0';

  return i;
}

int getIndex(char src[], char stringToFind[], int maxLen){
  int matchIndex = -1;

  int i; 
  char c;
  char cMatch;

  for (i = 0; i < maxLen && (c = src[i]) != '\0'; i ++){
    cMatch = matchIndex == -1 ? stringToFind[0] : stringToFind[i - matchIndex];
    if (cMatch == '\0') return matchIndex;

    if (matchIndex == -1){
      if (c == cMatch){
        matchIndex = i;
      }
    } else if (c != cMatch){
      matchIndex = -1;
    }
  }

  return -1;
}
