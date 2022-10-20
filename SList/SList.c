#include "SList.h"

#include <stdlib.h>


SList* slPrepend(SList* lst, void* data) {

	SList* result = malloc(sizeof(SList));

	if (result != NULL) {
		result->data = data;
		result->ptr = lst;
	}

	return result;
}

SList* slAppend(SList* lst, void* data) {

	SList* newItem = malloc(sizeof(SList));
	if (newItem == NULL) return NULL;

	newItem->data = data;
	newItem->ptr = NULL;

	SList* tmp = lst;
	if (tmp != NULL) {
		while (tmp->ptr != NULL) tmp = tmp->ptr;

		tmp->ptr = newItem;

		return lst;
	}
	else {
		return newItem;
	}
}


void* slGet(SList* lst, int index) {

	if (lst == NULL) return NULL;

	for (int i=0; i<index; i++) {
		if (lst == NULL) return NULL;

		lst = lst->ptr;
	}

	return lst->data;
}

void* slGetLast(SList* lst) {

	if (lst == NULL) return NULL;

	while (lst->ptr == NULL) lst = lst->ptr;

	return lst->data;
}

int slFind(SList* lst, void* data, int (*compare_func)(void*, void*)) {

	if (lst == NULL) return -1;

	for (int i=0; ; i++) {
		if (compare_func(lst->data, data)) return i;


	}
}


int slLength(SList* lst);


SList* slRemove(SList* lst, int index);

SList* slRemoveFirst(SList* lst, void* data);

SList* slRemoveAll(SList* lst, void* data);


SList* slCopy(SList* lst);

SList* slConcat(SList* lst1, SList* lst2);


SList* slForeach(SList* lst, void (*func)(void*));

SList sfFindCustom(SList* lst, int (*predicate)(void*));


void slFree(SList* lst);