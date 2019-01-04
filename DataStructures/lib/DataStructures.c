#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "DataStructures.h"

//STACK
  stack *Stack_Create() {
    stack *newStack = (stack *) malloc(sizeof(stack));
    if(!newStack) return NULL;
    newStack->size = 1;
    newStack->top = -1;
    newStack->array = (int *) malloc(sizeof(int));
    if(!newStack->array) return NULL;
    return newStack;
  }

  void Stack_Delete(stack *stackArg) {
    if(stackArg) {
      if(stackArg->array) free(stackArg->array);
      free(stackArg);
    }
  }

  bool Stack_Push(stack *stackArg, int data) {
    if(Stack_IsFull(stackArg)) {
      if(!Stack_Double(stackArg)) return false;
    }
    stackArg->array[++stackArg->top] = data;
    return true;
  }

  int Stack_Pop(stack *stackArg) {
    if(Stack_IsEmpty(stackArg)) {
      printf("DataStructures Warning: Attempting to pop from empty stack.\n");
      return INT_MIN;
    }
    return stackArg->array[stackArg->top--];
  }

  int Stack_GetTopValue(stack *stackArg) {
    if (Stack_IsEmpty(stackArg)) {
      printf("DataStructures Warning: Attempting to get top value from empty stack.\n");
      return INT_MIN;
    }
    return stackArg->array[stackArg->top];
  }

  bool Stack_Double(stack *stackArg) {
    stackArg->size *= 2;
    stackArg->array = (int *) realloc(stackArg->array, stackArg->size * sizeof(int));
    if (!stackArg->array) {
      printf("DataStructures Error: Stack array reallocation failed.\n");
      return false;
    }
    return true;
  }

  bool Stack_IsFull(stack *stackArg) {
    return stackArg->top == stackArg->size - 1;
  }

  bool Stack_IsEmpty(stack *stackArg) {
    return stackArg->top == -1;
  }
//STACK END

//QUEUE
  queue *Queue_Create() {
    queue *newQueue = (queue *) malloc(sizeof(queue));
    if(!newQueue) return NULL;
    newQueue->bottom = -1;
    newQueue->size = 1;
    newQueue->array = (int *) malloc(sizeof(int));
    if(!newQueue->array) return NULL;
    return newQueue;
  }

  void Queue_Delete(queue *queueArg) {
    if (queueArg) {
      if (queueArg->array) {
        free(queueArg);
      }
    }
  }

  bool Queue_Enqueue(queue *queueArg, int data) {
    if (queueArg->bottom == queueArg->size - 1) {
      if (!Queue_Double(queueArg)) return false;
    }
    queueArg->array[++queueArg->bottom] = data;
    return true;
  }

  int Queue_Dequeue(queue *queueArg) {
    if (queueArg->bottom == -1) {
      printf("DataStructures Warning: Attempting to dequeue from empty queue.\n");
      return INT_MIN;
    }
    int returnVal = queueArg->array[0];
    queueArg->bottom--;
    for (int i = 0; i <= queueArg->bottom; i++) {
      queueArg->array[i] = queueArg->array[i + 1];
    }
    return returnVal;
  }

  bool Queue_Double(queue *queueArg) {
    queueArg->size *= 2;
    queueArg->array = (int *) realloc(queueArg->array, queueArg->size * sizeof(int));
    if (!queueArg->array) {
      printf("DataStructures Error: Queue array reallocation failed.\n");
      return false;
    }
    return true;
  }

  int Queue_GetTopValue(queue *queueArg) {
    if (queueArg->bottom != -1) {
      return queueArg->array[0];
    }
    else {
      printf("DataStructures Warning: Attempting to get top value from empty queue.\n");
      return INT_MIN;
    }
  }

  bool Queue_IsEmpty(queue *queueArg) {
    return queueArg->bottom == -1;
  }

  bool Queue_IsFull(queue *queueArg) {
    return queueArg->bottom == queueArg->size - 1;
  }
//QUEUE END
