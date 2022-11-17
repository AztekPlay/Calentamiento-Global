#ifndef _TSTACK_H_
#define _TSTACK_H_

#include <stddef.h>


typedef struct Stack Stack;


Stack* stackCreate();  // Must be free with stackDestroy after use

void stackDestroy(Stack* stack);

int stackPush(Stack* stack, void* data);

size_t stackSize(Stack* stack);

void* stackPop(Stack* stack);

void* stackPeek(Stack* stack);

void stackTune(Stack* stack, unsigned  initialSize, unsigned increment);


#endif
