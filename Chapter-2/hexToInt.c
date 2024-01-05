#include <stdio.h>

int hexCharToString(char c);

int main (){
  int result = 0;
  unsigned int digit = 0;

  for (char input; (scanf("%c", &input) == 1) && input != '\n';){
    digit = hexCharToString(input);

    if (digit == -1) {
      printf("invaild char: %c\n", input);
      return -1;
    };

    result = result * 16 + digit;
  }
  printf("%d\n", result);

  return 0;
}

int hexCharToString(char c){
  if (c >= '0' && c <= '9') return c - '0';
  if (c >= 'a' && c <= 'f') return c - 'a' + 10;
  if (c >= 'A' && c <= 'F') return c - 'A' + 10;
  return -1;
}

