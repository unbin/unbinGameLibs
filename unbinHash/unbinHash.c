#include "unbinHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 10
#define CHARREADSIZE 1000
#define FILEREADSIZE 1000

char *unbinHash_hashString(const char *string) {
  //SETUP:
  char *hashedValue = (char *) calloc(HASHSIZE, sizeof(char));
  if (!hashedValue) {
    fprintf(stderr, "unbinHash Error: Could not allocate dynamic memory.\n");
    return 0;
  }
  const int stringLen = strlen(string);
  for (int i = 0; i < HASHSIZE; i++) {
    hashedValue[i] = string[i];
  }
  //HASH:
  if (stringLen <= HASHSIZE) strcpy(hashedValue, string);
  else {
    short int counter = 0;
    for (int i = HASHSIZE; i < stringLen; i++, counter++) {
      if (counter > HASHSIZE - 1) counter = 0;
      hashedValue[counter] ^= string[i];
    }
  }
  return hashedValue;
}

char *unbinHash_hashFile(const char *path) {
  FILE *fp = fopen(path, "r");
  if (!fp) {
    fprintf(stderr, "unbinHash Error: Could not open file %s for reading.\n", path);
    return 0;
  }
  char charBuffer[CHARREADSIZE];
  char fileBuffer[FILEREADSIZE];
  char *returnHash = (char *) calloc(10, sizeof(char));
  if (!returnHash) {
    fprintf(stderr, "unbinHash Error: Could not allocate dynamic memory.\n");
    return 0;
  }
  while (fscanf(fp, "%s", charBuffer) != EOF) {
    strcat(fileBuffer, charBuffer);
  }
  strcpy(returnHash, unbinHash_hashString(fileBuffer));
  return returnHash;
}

void unbinHash_displayString(const char *string) {
  if (string) {
    printf("ASCII: %s\nHex: ", string);
    for (size_t i = 0; i < HASHSIZE; i++) {
      printf("%x ", string[i]);
    }
    printf("\nDecimal: ");
    for (size_t i = 0; i < HASHSIZE; i++) {
      printf("%d ", string[i]);
    }
    printf("\n");
  }
  else printf("unbinHash Error: Could not display string - null pointer.\n");
}
