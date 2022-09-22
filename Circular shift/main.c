#include <stdio.h>


//Declarations
void input(int* a);

int nonZeroBits(int a);


//Main
int main() {

	int a;
	input(&a);

	printf("Number of non-zero bits: %i\n", nonZeroBits(a));

	return 0;
}


//Definitions
void input(int* a) {

	printf("Enter number: ");
	scanf("%i", a);
}

int nonZeroBits(int a) {

	int res = 0;
	int intSize = 8*sizeof(int);
	int bitMask = 1;

	for (int i=0; i<intSize; i++) {
		if ((a & bitMask) != 0) {
			res++;
		}

		bitMask = bitMask << 1;
	}

	return res;
}