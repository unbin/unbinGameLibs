#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

//STACK
  //TYPE
    typedef struct stack_s {
      int top;
      int size;
      int *array;
    } stack;
  //TYPE END
  //FUNCTIONS
    stack *Stack_Create();
    void Stack_Delete(stack*);
    bool Stack_Push(stack*, int data);
    int Stack_Pop(stack*);
    int Stack_GetTopValue(stack*);
    bool Stack_Double(stack*);
    bool Stack_IsFull(stack*);
    bool Stack_IsEmpty(stack*);
  //FUNCTIONS END
//STACK END

//QUEUE
  //TYPE
    typedef struct queue_s {
      int bottom;
      int size;
      int *array;
    } queue;
  //TYPE END
  //FUNCTIONS
    queue *Queue_Create();
    void Queue_Delete(queue*);
    bool Queue_Enqueue(queue*, int);
    int Queue_Dequeue(queue*);
    bool Queue_Double(queue*);
    int Queue_GetTopValue(queue*);
    bool Queue_IsEmpty(queue*);
    bool Queue_IsFull(queue*);
  //FUNCTIONS END
//QUEUE END
#endif
