#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 10
//'#define DEBUG' for debug information.

char *hash(const char *string) {
  //SETUP:
    #ifdef DEBUG
    printf("Debug: Passed string to hash funtion: %s\n",string);
    #endif
    //hash length = 10 chars.
    char *hashedValue = (char *) malloc(sizeof(char) * HASHSIZE);
    const int stringLen = strlen(string);
    for (int i = 0; i < HASHSIZE; i++) {
      hashedValue[i] = string[i];
    }
    //const int stringVal = string[1];
    #ifdef DEBUG
    printf("Debug: Argument string length: %d\n", stringLen);
    //printf("Debug: Argument string value: %d\n", stringVal);
    #endif
  //HASH:
  if (stringLen <= HASHSIZE) strcpy(hashedValue, string);
  else {
    short int counter = 0;
    for (int i = HASHSIZE; i < stringLen; i++) {
      counter++;
      if (counter > HASHSIZE - 1) counter = 0;
      hashedValue[counter] &= string[i];
    }
  }
  return hashedValue;
}

void displayHash(const char *string, char *hashedValue) {
  printf("Hash of string \"%s\" is: \nASCII: %s\nHex: ", string, hashedValue);
  for (size_t i = 0; i < HASHSIZE; i++) {
    printf("%x ", hashedValue[i]);
  }
  printf("\nDecimal: ");
  for (size_t i = 0; i < HASHSIZE; i++) {
    printf("%d ", hashedValue[i]);
  }
  printf("\n");
}

void cleanup(char *hashedValue) {
  free(hashedValue);
}

int main(int argc, char const *argv[]) {
  if (argc > 1) {
    char *hashedValue = hash(argv[1]);
    displayHash(argv[1], hashedValue);
    cleanup(hashedValue);
  }
  else printf("Please input a string to hash.\n");
  return 0;
}
