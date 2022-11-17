#include "PriorityQueue.h"

#include <stdlib.h>


struct PriorityQueue {
	pqData** heap;
	size_t size;
	size_t maxSize;
	CmpFunc cmp;
};

static void descendingHeapify(PriorityQueue* pq);

static void ascendingHeapify(PriorityQueue* pq);

static void swap(pqData** a, pqData** b);


PriorityQueue* pqCreate(CmpFunc cmp) {

	PriorityQueue* result = malloc(sizeof(PriorityQueue));

	if (result != NULL) {
		result->heap = malloc(sizeof(pqData*)*10);

		if (result->heap == NULL) {
			free(result);
			result = NULL;
		}
		else {
			result->size = 0;
			result->maxSize = 10;
			result->cmp = cmp;
		}
	}

	return result;
}

void pqDestroy(PriorityQueue* pq) {
	if (pq != NULL) {
		free(pq->heap);
		free(pq);
	}
}

int pqInsert(PriorityQueue* pq, pqData* data) {

	int result = 0;

	if (pq != NULL) {
		if (pq->size == pq->maxSize) {
			pqData** tmp = realloc(pq->heap, 2*(pq->maxSize)*sizeof(pqData*));
			if (tmp != NULL) {
				pq->heap = tmp;
				pq->maxSize = 2*(pq->maxSize);
			}
			else result = 1;
		}

		if (!result) {
			pq->heap[pq->size] = data;
			pq->size++;

			descendingHeapify(pq);
		}
	}
	else result = 1;

	return result;
}

pqData* pqPeekMax(PriorityQueue* pq) {
	return (pq != NULL && pq->heap != NULL) ? pq->heap[0] : NULL;
}

pqData* pqPullMax(PriorityQueue* pq) {

	pqData* result = NULL;

	if (pq != NULL) {
		if (pq->size != 0) {
			pq->size--;
			result = pq->heap[0];
			pq->heap[0] = pq->heap[pq->size];

			ascendingHeapify(pq);
		}
		else result = NULL;
	}
	else result = NULL;

	return result;
}

int pqIsEmpty(PriorityQueue* pq) {
	return (pq != NULL && pq->size != 0) ? 0 : 1;
}


static void descendingHeapify(PriorityQueue* pq) {
	size_t ind = (pq->size == 0) ? 0: pq->size - 1;
	size_t parentInd;

	while (ind != 0) {
		parentInd = (ind-1)/2;

		if (pq->cmp((pq->heap[ind])->priority, (pq->heap[parentInd])->priority)) {
			swap((pq->heap + ind), (pq->heap + parentInd));
			ind = parentInd;
		}
		else ind = 0;
	}
}

static void ascendingHeapify(PriorityQueue* pq) {
	size_t ind = 0;
	size_t leftChildInd, rightChildInd;

	while (2*ind + 1 < pq->size) {
		leftChildInd = 2*ind + 1;
		rightChildInd = 2*ind + 2;

		if (rightChildInd < pq->size) {
			if (pq->cmp((pq->heap[rightChildInd])->priority, (pq->heap[leftChildInd])->priority))
				leftChildInd = rightChildInd;
		}

		if (pq->cmp((pq->heap[leftChildInd])->priority, (pq->heap[ind])->priority)) {
			swap((pq->heap + leftChildInd), (pq->heap + ind));
			ind = leftChildInd;
		}
		else ind = pq->size;
	}
}

static void swap(pqData** a, pqData** b) {
	pqData* tmp = *a;
	*a = *b;
	*b = tmp;
}