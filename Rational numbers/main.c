#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Rational.h"


//Main
int main() {

	srand((unsigned) time(NULL));


	int num1 = (rand()%1001) - 500;
	int num2 = (rand()%1001) - 500;
	int num3 = (rand()%1001) - 500;
	int num4 = (rand()%1001) - 500;
	int pwr = (rand()%7) - 3;

	size_t strSize = 200;

	char* str = malloc(strSize*sizeof(char));

	Rational* aa = create(num1, num2);
	Rational a = *aa;

	Rational b;
	set(&b, num3, num4);

	Rational c;

	if (aa != NULL && str != NULL) {

		RatToStr(a, str, strSize);
		printf("a = (%i)/(%i) = %s = %f\n", num1, num2, str, RatToFloat(a));

		RatToStr(b, str, strSize);
		printf("b = (%i)/(%i) = %s ~= %i\n", num3, num4, str, RatToInt(b));

		printf(compare(a, b) ? ((compare(a, b) == 1) ? "a > b\n" : "a < b\n") : "a = b\n");

		if (!add(&c, a, b)) {
			RatToStr(c, str, strSize);
			printf("a + b = %s\n", str);
		}

		if (!sub(&c, a, b)) {
			RatToStr(c, str, strSize);
			printf("a - b = %s\n", str);
		}

		if (!mul(&c, a, b)) {
			RatToStr(c, str, strSize);
			printf("a*b = %s\n", str);
		}

		if (!division(&c, a, b)) {
			RatToStr(c, str, strSize);
			printf("a/b = %s\n", str);
		}

		if (!power(&c, a, pwr)) {
			RatToStr(c, str, strSize);
			printf("a^(%i) = %s\n", pwr, str);
		}
	}


	free(str);
	free(aa);

	return 0;
}