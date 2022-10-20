
struct SList;

typedef struct SList {
	void* data;
	struct SList* ptr;
} SList;


SList* slPrepend(SList* lst, void* data);

SList* slAppend(SList* lst, void* data);


void* slGet(SList* lst, int index);

void* slGetLast(SList* lst);

int slFind(SList* lst, void* data, int (*compare_func)(void*, void*));


int slLength(SList* lst);


SList* slRemove(SList* lst, int index);

SList* slRemoveFirst(SList* lst, void* data);

SList* slRemoveAll(SList* lst, void* data);


SList* slCopy(SList* lst);

SList* slConcat(SList* lst1, SList* lst2);


SList* slForeach(SList* lst, void (*func)(void*));

SList sfFindCustom(SList* lst, int (*predicate)(void*));


void slFree(SList* lst);