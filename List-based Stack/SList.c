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

	while (lst->ptr != NULL) lst = lst->ptr;

	return lst->data;
}

size_t slFind(SList* lst, void* data, int (*equalityFunc)(void*, void*)) {

	if (lst == NULL) return -1;

	for (size_t i=0; lst != NULL; i++) {
		if (equalityFunc(lst->data, data)) return i;

		lst = lst->ptr;
	}

	return -1;
}


size_t slLength(SList* lst) {

	size_t i = 0;

	for (i; lst != NULL; i++) lst = lst->ptr;

	return i;

}


SList* slRemove(SList* lst, int index) {

	if (lst == NULL) return NULL;

	int i = 0;

	if (index == 0) {
		SList* tmp = lst;
		lst = lst->ptr;
		free(tmp);
	}
	else {
		if (lst->ptr == NULL) return NULL;

		SList* tmp = lst;

		for (i; i<index-1; i++) {
			tmp = tmp->ptr;

			if (tmp->ptr == NULL) return NULL;
		}

		SList* tmp2 = tmp->ptr;
		tmp->ptr = tmp->ptr->ptr;
		free(tmp2);
	}

	return lst;
}

SList* slRemoveFirst(SList* lst, void* data, int (*equalityFunc)(void*, void*)) {

	if (lst == NULL) return NULL;

	if (equalityFunc(lst->data, data)) {
		SList* tmp = lst;
		lst = lst->ptr;
		free(tmp);
	}
	else {
		SList* tmp = lst;

		for (int i = 0; tmp->ptr != NULL; i++) {
			if (equalityFunc(tmp->ptr->data, data)) {
				SList* tmp2 = tmp->ptr;
				tmp->ptr = tmp->ptr->ptr;
				free(tmp2);

				return lst;
			}

			tmp = tmp->ptr;
		}
	}

	return lst;
}

SList* slRemoveAll(SList* lst, void* data, int (*equalityFunc)(void*, void*)) {

	if (lst == NULL) return NULL;

	if (equalityFunc(data, lst->data)) {
		SList* tmp = lst;
		lst = lst->ptr;
		free(tmp);
	}
	else {
		SList* tmp = lst;

		while (tmp->ptr != NULL) {
			if (equalityFunc(data, tmp->ptr->data)) {
				SList* tmp2 = tmp->ptr;
				tmp->ptr = tmp->ptr->ptr;
				free(tmp2);
			}
			else tmp = tmp->ptr;
		}
	}

	return lst;
}


SList* slCopy(SList* lst) {

	SList* result = NULL;
	SList* tmp;

	while (lst != NULL) {
		tmp = slAppend(result, lst->data);

		if (tmp == NULL) {
			slFree(result);

			return NULL;
		}

		result = tmp;
		lst = lst->ptr;
	}

	return result;
}

SList* slConcat(SList* lst1, SList* lst2) {

	if (lst1 == NULL) return lst2;

	while (lst1->ptr != NULL) lst1 = lst1->ptr;

	lst1->ptr = lst2;

	return lst1;
}


void slForeach(SList* lst, void (*func)(void*)) {

	while (lst != NULL) {
		func(lst->data);

		lst = lst->ptr;
	}
}

size_t slFindCustom(SList* lst, int (*predicate)(void*)) {

	for (size_t i = 0; lst != NULL; i++) {
		if (predicate(lst->data)) return i;

		lst = lst->ptr;
	}

	return -1;
}


void slFree(SList* lst) {
	
	SList* tmp;

	while (lst != NULL) {
		tmp = lst;
		lst = lst->ptr;
		free(tmp);
	}
}