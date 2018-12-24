#include "unbinSave.h"
#include <iostream>

bool unbinSave_Save(std::string path, std::string saveData) {
  bool success = true;
  FILE *fp = fopen(path.c_str(), "w");
  if (fp == NULL) {
    std::cout << "unbinSave Error: Could not open file " << path << " for writing.\n";
    success = false;
  }
  else if (fprintf(fp, "%s\n", saveData.c_str()) < 0) {
    std::cout << "unbinSave Error: Could not write save data to file.\n";
    success = false;
  }
  if (fp != NULL) fclose(fp);
  return success;
}

bool unbinSave_Load(std::string path, char *saveData) {
  bool success = true;
  FILE *fp = fopen(path.c_str(), "r");
  if (fp == NULL) {
    std::cout << "unbinSave Error: Could not open file " << path << " for reading.\n";
    success = false;
  }
  else if (fgets(saveData, 200, fp) == NULL) {
    std::cout << "unbinSave Error: Could not read save data from " << path << ".\n";
    success = false;
  }
  if (fp != NULL) fclose(fp);
  return success;
}
