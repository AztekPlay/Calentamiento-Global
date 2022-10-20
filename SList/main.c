#include <stdlib.h>
#include <stdio.h>

#include "SList.h"


int main() {

	int a = 5;
	char b = '\003';
	SList* allah = slAppend(NULL, &a);
	slAppend(allah, &b);
	printf("%i\n", *((int*) slGet(allah, 0)));
	printf("%c\n", *((char*) slGet(allah, 1)));


	return 0;
}