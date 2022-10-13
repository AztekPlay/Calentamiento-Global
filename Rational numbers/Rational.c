#include "Rational.h"

#include <stdlib.h>


struct Rational {
	int numer;
	int denom;
};


Rational* create(int numer, int denom) {

	Rational* result = (Rational*) malloc(sizeof(Rational));
	
	if (result != NULL) {
		result->numer = numer;
		result->denom = denom;
	}

	return result;
}

int compare(Rational* a, Rational* b) {

}

Rational* add(Rational* a, Rational* b) {

}

Rational* sub(Rational* a, Rational* b) {

}

Rational* mul(Rational* a, Rational* b) {

}

Rational* adiv(Rational* a, Rational* b) {

}

Rational* power(Rational* r, int power) {

}

int RatToInt(Rational* r) {
	return r->numer/r->denom;
}

float RatToFloat(Rational* r) {

}

char* RatToStr(Rational* r) {

}