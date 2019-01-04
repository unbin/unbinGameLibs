#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "./../lib/DataStructures.h"

int main() {
  queue *testQueue = Queue_Create();
  if (Queue_IsEmpty(testQueue)) printf("Queue is empty\n");
  else if (Queue_IsFull(testQueue)) printf("Queue is full\n");
  else printf("Queue is neither empty or full\n");
  printf("Size of queue: %d\n", testQueue->size);
  for (int i = 1; i <= 100; i++) {
    Queue_Enqueue(testQueue, i * 2);
  }
  for (int i = 0; i < 100; i++) {
    if (i == 99) {
      printf("Get: %d\n", Queue_GetTopValue(testQueue));
      if (Queue_IsEmpty(testQueue)) printf("Queue is empty\n");
      else if (Queue_IsFull(testQueue)) printf("Queue is full\n");
      else printf("Queue is neither empty nor full\n");
    }
    printf("Deqeueue #%d:\t%d\n", i + 1, Queue_Dequeue(testQueue));
  }
  if (Queue_IsEmpty(testQueue)) printf("Queue is empty\n");
  else if (Queue_IsFull(testQueue)) printf("Queue is full\n");
  else printf("Queue is neither empty or full\n");
  printf("Size of queue: %d\n", testQueue->size);
  Queue_Delete(testQueue);
}
