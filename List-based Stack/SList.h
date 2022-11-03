#ifndef _SLIST_H_
#define _SLIST_H_


struct SList;

typedef struct SList {
	void* data;
	struct SList* ptr;
} SList;


SList* slPrepend(SList* lst, void* data);

SList* slAppend(SList* lst, void* data);


void* slGet(SList* lst, int index);

void* slGetLast(SList* lst);

size_t slFind(SList* lst, void* data, int (*equalityFunc)(void*, void*));  // equalityFunc(data, lstData)


size_t slLength(SList* lst);


SList* slRemove(SList* lst, int index);

SList* slRemoveFirst(SList* lst, void* data, int (*equalityFunc)(void*, void*));  // equalityFunc(data, lstData)

SList* slRemoveAll(SList* lst, void* data, int (*equalityFunc)(void*, void*));  // equalityFunc(data, lstData)


SList* slCopy(SList* lst);

SList* slConcat(SList* lst1, SList* lst2);


void slForeach(SList* lst, void (*func)(void*));

size_t slFindCustom(SList* lst, int (*predicate)(void*));

void slFree(SList* lst);


#endif