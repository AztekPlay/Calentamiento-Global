#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "SList.h"


int cmpf(void* a, void* b) {
	return (0 > *((int*)b));
}

void frc(void* a) {
	printf("%i ", *((int*) a));
}

int pred(void* a) {
	return (*((int*) a) < 0);
}

int main() {

	srand((unsigned) time(NULL));

	int data[10];
	for (int i=0; i<10; i++) data[i] = ((rand()%2)*2 - 1)*rand();

	SList* allah = NULL;
	for (int i=0; i<10; i++) {
		SList* tmp = slAppend(allah, (void*) (data + i));

		if (tmp == NULL) break;

		allah = tmp;
	}

	printf("size = %zi, last = %i \n", slLength(allah), *((int*) slGetLast(allah)));
	slForeach(allah, frc);

	for (int i=9; i>=6; i--) allah = slRemove(allah, 0);
	printf("\nsize = %zi\n", slLength(allah));
	slForeach(allah, frc);

	allah = slRemoveAll(allah, NULL, cmpf);
	printf("\nsize = %zi\n", slLength(allah));
	slForeach(allah, frc);

	slFree(allah);

	return EXIT_SUCCESS;
}