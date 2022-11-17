#include "TODO-list.h"

#include <stdio.h>
#include <stdlib.h>

#include "PriorityQueue.h"


static int cmp(void* a, void* b) {
	return (*((int*) a) > *((int*) b));
}

static int input(char* str, int maxLen, int* prior) {

}

static int createData(pqData** data, char*** str, int** prior);

static int expandData(pqData** data, char*** str, int** prior, size_t* dataSize);

static int deleteData(pqData** data, char*** str, int** prior, size_t* dataSize);


void TODOList() {

	pqData* data;
	char** str;
	int* prior;

	size_t dataSize = 10;

	if (!createData(&data, &str, &prior)) {

	}

	if (data != NULL) {
		int closeTODOList = 0;

		char str[255];
		int prior;

		while (!closeTODOList) {
			
		}
	}
}

static int createData(pqData** data, char*** str, int** prior) {
	int result = 1;

	*data = malloc(10*sizeof(pqData));
	*str = malloc(10*sizeof(char*));
	*prior = malloc(10*sizeof(int));

	if (*data != NULL && *str != NULL && *prior != NULL) {
		for (int i = 0; i<10; i++) {
			*(*str + i) = malloc(255*sizeof(char));

			if (*(*str + i) != NULL) {
				(*data + i)->data = (void*) *(*str + i);
				(*data + i)->priority = (void*) (*prior + i);
			}
			else {
				result = 0;

				for (int j = 0; j<i; i++) free(*(*str + j));
			}
		}
	}
	else result = 0;

	if (!result) {
		free(*data);
		free(*str);
		free(*prior);
	}

	return result;
}
