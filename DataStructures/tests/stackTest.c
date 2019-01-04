#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "./../lib/DataStructures.h"

int main() {
  stack *s = createStack();
  push(s, 10);
  push(s, 20);
  if (!isStackEmpty(s)) printf("Stack is not empty\n");
  else printf("Stack is empty\n");
  printf("stack top = %d\n", pop(s));
  if (isStackEmpty(s)) printf("Stack is empty\n");
  else printf("Stack is not empty\n");
  printf("stack top = %d\n", pop(s));
  if (isStackEmpty(s)) printf("Stack is empty\n");
  else printf("Stack is not empty\n");
}
