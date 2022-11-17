#include <stdio.h>
#include <assert.h>

#include "Stack.h"


int main() {

	int data[4] = {20, -81, 7, 23322};

	Stack* allah = stackCreate();

	if (allah != NULL) {

		stackTune(allah, 20, 20);

		for (int i = 0; i<80; i++) {
			int res = stackPush(allah, (void*) (data + i%4));

			assert(!res);

			printf("%i ", *(data + i%4));
		}

		printf("\nsize = %zi\n", stackSize(allah));

		while (stackSize(allah) != 0) {
			int tmp1 = *((int*) stackPeek(allah));
			assert(tmp1 != 0);

			int tmp2 = *((int*) stackPop(allah));
			assert(tmp2 != 0);

			printf("(%i %i) ", tmp1, tmp2);
		}

		stackDestroy(allah);
	}

	return 0;
}