#include <stdio.h>
#include <math.h>


//Definitions
unsigned int summ(int a);

unsigned int composition(int a);

unsigned int boundedComposition(int a);

unsigned int allBoundedCompositions();      // 1,000

unsigned int luckyTickets();                // 55,252     (including 000 000)

unsigned int allTickets();                  // 1,000,000

float luckyTicketsPercentage();             // 5.5252%    (including 000 000)


//Main
int main() {

	printf("Number of lucky tickets: %u\nPercent of lucky tickets: %2.4f%%\n", 
		   luckyTickets(), luckyTicketsPercentage());

	return 0;
}


//Declarations
unsigned int summ(int a) {

	return a*(a+1)/2;
}

unsigned int composition(int a) {

	return (a+1)*(a+2)/2;
}

unsigned int boundedComposition(int a) {

	unsigned int res = 0;

	if (a <= 9) {
		res = composition(a);
	}
	else if (a <= 13) {
		res = composition(a) - 3*summ(a-9);
	}
	else {
		res = boundedComposition(27 - a);
	}

	return res;
}

unsigned int allBoundedCompositions() {

	unsigned int res = 0;

	for (int i=0; i<=27; i++) {
		res += boundedComposition(i);
	}

	return res;
}

unsigned int luckyTickets() {

	unsigned int res = 0;

	for (int i=0; i<=27; i++) {
		res += pow(boundedComposition(i), 2);
	}

	return res;
}

unsigned int allTickets() {

	return pow(allBoundedCompositions(), 2);
}

float luckyTicketsPercentage() {

	return 100.f/allTickets()*luckyTickets();
}