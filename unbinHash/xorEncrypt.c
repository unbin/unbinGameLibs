#include <stdio.h>

int main() {
  //init
  char str[64];
  char key[64];
  int strsize = 0;
  int keysize = 0;
  char output[64];
  printf("input your string: ");
  scanf("%s",str);
  printf("input your key: ");
  scanf("%s",key);
  //get string size
  for (int i = 0; i < 64; i++) {
    if (str[i] != '\0') strsize++;
    else break;
  }
  //get key size
  for (int i = 0; i < 64; i++) {
    if (key[i] != '\0') keysize++;
    else break;
  }
  //extend key if smaller than string size
  if (strsize > keysize) {
    int orgnlKeySize = keysize;
    int loc = 0;
    for (; keysize < strsize; keysize++) {
      key[keysize] = key[loc];
      key[keysize + 1] = '\0';
      loc++;
      if (loc >= orgnlKeySize) loc = 0;
    }
  }
  //shorten key if larger than string size
  if (keysize > strsize) key[strsize] = '\0';
  //string XOR key
  for (int i = 0; i < strsize; i++) {
    output[i] = str[i] ^ key[i];
    output[i + 1] = '\0';
  }
  //print values
  printf("str: %s\n", str);
  printf("key: %s\n",key);
  printf("output(ASCII): ");
  for (int i = 0; i < strsize; i++) {
    if (output[i] < 32 || output[i] == 127) {
      printf("[%d]", output[i]);
    }
    else printf("%c",output[i]);
  }
  printf("\noutput(decimal): ");
  for (int i = 0; i < strsize; i++) {printf("%d ",output[i]);}
  printf("\n");
}
