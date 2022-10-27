#include <stdio.h>

#include "Stack.h"


int main() {

	int data[4] = {20, -81, 7, 23322};

	Stack* allah = stCreate();
	
	if (allah != NULL) {

		stSet(allah, 100, 100);
		
		for (int i=0; i<80; i++) {
			if (stPush(allah, (void*) (data + i%4))) break;

			printf("%i ", *(data + i%4));
		}

		printf("\nsize = %zi\n", stSize(allah));

		while (stSize(allah) != 0) {
			int tmp1 = *((int*) stPeek(allah));
			int tmp2 = *((int*) stPop(allah));

			printf("(%i %i) ", tmp1, tmp2);
		}

		stDestroy(allah);
	}

	return EXIT_SUCCESS;
}