#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//'#define DEBUG' for debug information.

char *hash(const char *string) {
  //SETUP:
    #ifdef DEBUG
    printf("Debug: Passed string to hash funtion: %s\n",string);
    #endif
    //hash length = 10 chars.
    char *hashedValue = (char *) malloc(sizeof(char) * 10);
    const int stringLen = strlen(string);
    //const int stringVal = string[1];
    #ifdef DEBUG
    printf("Debug: Argument string length: %d\n", stringLen);
    //printf("Debug: Argument string value: %d\n", stringVal);
    #endif
  //HASH:
  return hashedValue;
}

void cleanup(char *hashedValue) {
  free(hashedValue);
}

int main(int argc, char const *argv[]) {
  if (argc > 1) {
    char *hashedValue = hash(argv[1]);
    #ifdef DEBUG
    printf("Debug: Returned hashed value: %s\n",hashedValue);
    #endif
    printf("Hash of string '%s' is %s\n", argv[1], hashedValue);
  }
  else printf("Please input a string to hash.\n");
  return 0;
}
