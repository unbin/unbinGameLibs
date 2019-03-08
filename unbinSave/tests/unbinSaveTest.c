#include "./../unbinSave.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("Usage: unbinSaveTest *string*\n");
    return 0;
  }
  char *loadData = calloc(1000, sizeof(char));
  unbinSave_Save("./testfile", argv[1]);
  unbinSave_Load("./testfile", loadData);
  printf("Loaded data from testfile: %s\n", loadData);
}
