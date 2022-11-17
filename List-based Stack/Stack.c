#include "Stack.h"

#include <stdlib.h>
#include <stdio.h>


typedef struct Node Node;

struct Node {
	Node* ptr;
	void* data;
};

struct Stack {
	Node* pHead;
	Node* pFree;
	size_t size;
	unsigned initialSize;
	unsigned increment;
};

static int addNodes(Node** tail, unsigned count);

static void freeQueue(Node* ptr);


Stack* stackCreate() {

	Stack* result = malloc(sizeof(Stack));

	if (result != NULL) {
		result->pHead = NULL;
		result->pFree = NULL;
		result->size = 0;
		result->initialSize = 10;
		result->increment = 5;
	}

	return result;
}

void stackDestroy(Stack* stack) {

	if (stack != NULL) {

		freeQueue(stack->pHead);
		freeQueue(stack->pFree);
		free(stack);
	}
}

int stackPush(Stack* stack, void* data) {

	int result = 0;

	if (stack != NULL) {
		if (stack->pFree == NULL) {
			if (addNodes(&(stack->pFree), stack->initialSize)) result = 1;
		}

		if (!result) {
			Node* tmp = stack->pFree;
			stack->pFree = stack->pFree->ptr;
			tmp->ptr = stack->pHead;
			stack->pHead = tmp;

			stack->pHead->data = data;

			stack->size++;
		}
	}
	else result = 1;

	return result;
}

size_t stackSize(Stack* stack) {

	return (stack != NULL) ? stack->size : -1;
}

void* stackPop(Stack* stack) {

	void* result = NULL;

	if (stack != NULL) {
		if (stack->pHead != NULL) {
			Node* tmp = stack->pHead;
			stack->pHead = stack->pHead->ptr;
			tmp->ptr = stack->pFree;
			stack->pFree = tmp;

			stack->size--;

			result = tmp->data;
		}
	}

	return result;
}

void* stackPeek(Stack* stack) {
	return (stack != NULL && stack->pHead != NULL) ? stack->pHead->data : NULL;
}

void stackTune(Stack* stack, unsigned  initialSize, unsigned increment) {
	
	if (stack != NULL) {
		if (initialSize != 0) stack->initialSize = initialSize;
		if (increment != 0) stack->increment = increment;
	}
}


static int addNodes(Node** tail, unsigned count) {

	Node* iter = *tail;

	for (unsigned i = 0; i<count; i++) {
		Node* tmp = (Node*) malloc(sizeof(Node));

		if (i == 0) *tail = tmp;
		else iter->ptr = tmp;

		if (tmp != NULL) {
			iter = tmp;
			iter->ptr = NULL;
		}
		else break;
	}

	return (*tail == NULL);
}

static void freeQueue(Node* ptr) {
	while (ptr != NULL) {
		Node* temp = ptr->ptr;
		free(ptr);
		ptr = temp;
	}
}
