#include "unbinSave.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define CHARREADSIZE 1000

bool unbinSave_Save(const char *path, const char *saveData) {
  FILE *fp = fopen(path, "w");
  if (fp) {
    if (fprintf(fp, "%s\n", saveData) < 0) {
      fprintf(stderr, "unbinSave Error: Could not write save data to %s\n", path);
      return false;
    }
    fclose(fp);
    return true;
  }
  fprintf(stderr, "unbinSave Error: Could not open file %s for writing\n", path);
  return false;
}

bool unbinSave_Load(const char *path, char *saveData) {
  FILE *fp = fopen(path, "r");
  if (fp) {
    char charBuffer[CHARREADSIZE];
    while (fscanf(fp, "%s", charBuffer) != EOF) {
      strcat(saveData, charBuffer);
    }
    fclose(fp);
    return true;
  }
  fprintf(stderr, "unbinSave Error: Could not open file %s for reading\n", path);
  return false;
}
