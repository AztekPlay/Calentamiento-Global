#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_


typedef struct PriorityQueue PriorityQueue;

typedef struct pqData {
	void* data;
	void* priority;
} pqData;

/// Must return 1 if a > b, and 0 if a <= b.
typedef int (*CmpFunc)(void* a, void* b);


/// Create empty priority queue.
/// Must be deallocated with pqDestroy() after use.
PriorityQueue* pqCreate(CmpFunc cmp);

void pqDestroy(PriorityQueue* pq);

/// Add data into the priority queue.
/// Returns 0 if data was inserted successfully, and 1 if not.
int pqInsert(PriorityQueue* pq, pqData* data);

/// Returns an element with highest priority.
pqData* pqPeekMax(PriorityQueue* pq);

/// Returns an element with highest priority and delete it from priority queue.
pqData* pqPullMax(PriorityQueue* pq);

/// Returns 1 if priority queue is empty, and 0 if not.
int pqIsEmpty(PriorityQueue* pq);


#endif