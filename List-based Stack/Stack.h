#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>


typedef struct Stack Stack;


Stack* stCreate();

void stDestroy(Stack* ptr);

void stClear(Stack* ptr);

int stPush(Stack* ptr, void* value);

void* stPop(Stack* ptr);

void* stPeek(Stack* ptr);

size_t stSize(Stack* ptr);

int stSet(Stack* ptr, size_t initial_size, size_t increment);


#endif