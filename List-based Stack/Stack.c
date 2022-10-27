#include "Stack.h"

#include <stdlib.h>


struct Stack {
	void** ptr;
	size_t size;
	size_t memsize;
	size_t meminit;
	size_t increment;
};


Stack* stCreate() {

	Stack* ptr = malloc(sizeof(Stack));
	if (ptr == NULL) return NULL;

	ptr->ptr = NULL;
	ptr->size = 0;
	ptr->memsize = 0;
	ptr->meminit = 50;
	ptr->increment = 50;

	return ptr;
}

void stDestroy(Stack* ptr) {
	free(ptr->ptr);
	free(ptr);
}

void stClear(Stack* ptr) {
	free(ptr->ptr);
	ptr->ptr = NULL;
	ptr->size = 0;
	ptr->memsize = 0;
}

int stPush(Stack* ptr, void* value) {

	if (ptr != NULL) {
		if ((ptr->size + 1)*sizeof(void*) >= ptr->memsize) {
			size_t newmemsize;

			if (ptr->memsize == 0) newmemsize = ptr->meminit;
			else newmemsize = ptr->memsize + ptr->increment;

			void** tmp = (void**) realloc(ptr->ptr, ptr->memsize + ptr->increment);
			if (tmp == NULL) return 2;

			ptr->ptr = tmp;
			ptr->memsize = newmemsize;
		}

		*(ptr->ptr + ptr->size) = value;
		ptr->size++;

		return 0;

	}
	else return 1;
}

void* stPop(Stack* ptr) {

	if (ptr != NULL && ptr->size != 0) {
		void* tmp = *(ptr->ptr + ptr->size - 1);
		*(ptr->ptr + ptr->size - 1) = NULL;

		ptr->size--;

		return tmp;
	}
	else return NULL;

}

void* stPeek(Stack* ptr) {

	if (ptr != NULL && ptr->ptr != NULL) return *(ptr->ptr + ptr->size - 1);
	else return NULL;
}

size_t stSize(Stack* ptr) {
	
	if (ptr != NULL) return ptr->size;
	else return 0;
}

int stSet(Stack* ptr, size_t initial_size, size_t increment) {
	
	if (ptr != NULL && initial_size > sizeof(void*) && increment > sizeof(void*)) {
		ptr->meminit = initial_size;
		ptr->increment = increment;

		return 0;
	}
	else return 1;
}