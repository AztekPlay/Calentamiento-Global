#include <stdio.h>

#include "Rational.h"

//Main
int main() {

	Rational* allah = create(10, 3);

	printf("%i\n", RatToInt(allah));

	free(allah);

	return 0;
}