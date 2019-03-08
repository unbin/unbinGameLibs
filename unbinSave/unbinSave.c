#include "unbinSave.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define CHARREADSIZE 1000

bool unbinSave_Save(const char *path, const char *saveData) {
  bool success = true;
  FILE *fp = fopen(path, "w");
  if (!fp) {
    fprintf(stderr, "unbinSave Error: Could not open file %s for writing\n", path);
    success = false;
  }
  else if (fprintf(fp, "%s\n", saveData) < 0) {
    fprintf(stderr, "unbinSave Error: Could not write save data to %s\n", path);
    success = false;
  }
  if (fp) fclose(fp);
  return success;
}

bool unbinSave_Load(const char *path, char *saveData) {
  bool success = true;
  FILE *fp = fopen(path, "r");
  if (!fp) {
    fprintf(stderr, "unbinSave Error: Could not open file %s for reading\n", path);
    success = false;
  }
  char charBuffer[CHARREADSIZE];
  while (fscanf(fp, "%s", charBuffer) != EOF) {
    strcat(saveData, charBuffer);
  }
  if (fp) fclose(fp);
  return success;
}
