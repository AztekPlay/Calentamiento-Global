#include "Rational.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef long long int wint;


static int wset(Rational* num, wint numer, wint denom);

static void wreduct(wint* numer, wint* denom);

static wint greatestCommonDivisor(wint a, wint b);


Rational* create(int numer, int denom) {

	Rational* result = NULL;

	if (denom) {

		result = (Rational*) malloc(sizeof(Rational));
		set(result, numer, denom);
	}

	return result;
}


int set(Rational* num, int numer, int denom) {

	return wset(num, (wint) numer, (wint) denom);
}

void reduct(Rational* num) {
	set(num, num->numer, num->denom);
}


int compare(Rational a, Rational b) {

	wint tmp = ((wint) (a.numer)*(b.denom)) - ((wint) (b.numer)*(a.denom));

	return (tmp == 0) ? 0 : ((tmp > 0) ? 1 : -1);

}

int add(Rational* res, Rational a, Rational b) {
	return wset(res,
		 ((wint)a.numer)*((wint)b.denom) + ((wint)b.numer)*((wint)a.denom),
		 ((wint)a.denom)*((wint)b.denom)
	);
}

int sub(Rational* res, Rational a, Rational b) {
	return wset(res,
		 ((wint)a.numer)*((wint)b.denom) - ((wint)b.numer)*((wint)a.denom),
		 ((wint)a.denom)*((wint)b.denom)
	);
}

int mul(Rational* res, Rational a, Rational b) {
	return wset(res,
		 ((wint)a.numer)*((wint)b.numer),
		 ((wint)a.denom)*((wint)b.denom)
	);
}

int division(Rational* res, Rational a, Rational b) {
	return wset(res,
		 ((wint)a.numer)*((wint)b.denom),
		 ((wint)a.denom)*((wint)b.numer)
	);
}

int power(Rational* res, Rational r, int power) {
	if (power >= 0) {
		return wset(res, 
			 (wint) pow(r.numer, power),
			 (wint) pow(r.denom, power)
		);
	}
	else {
		return wset(res,
			 (wint) pow(r.denom, -power),
			 (wint) pow(r.numer, -power)
		);
	}
}


int RatToInt(Rational r) {

	return r.numer/r.denom;
}

float RatToFloat(Rational r) {

	return ((float) r.numer)/(r.denom);
}

int RatToStr(Rational r, char* str, size_t strSize) {

	if (_itoa_s(r.numer, str, strSize, 10) != 0) return 1;

	if (r.denom != 1) {

		size_t len = strlen(str);

		if (len == strSize) return 1;

		str[len] = '/';
		if (_itoa_s(r.denom, str + len + 1, strSize - len - 1, 10) != 0) return 1;
	}

	return 0;
}


static int wset(Rational* num, wint numer, wint denom) {

	if (num != NULL && denom) {

		wreduct(&numer, &denom);

		num->numer = (int) numer;
		num->denom = (int) denom;

		return 0;
	}
	else return 1;
}

static void wreduct(wint* numer, wint* denom) {

	if (*denom < 0) {
		*numer = -(*numer);
		*denom = -(*denom);
	}

	wint gcd = greatestCommonDivisor(*numer, *denom);

	*numer /= gcd;
	*denom /= gcd;
}

static wint greatestCommonDivisor(wint a, wint b) {

	wint shift;

	a = (a<0) ? -a : a;
	b = (b<0) ? -b : b;

	if (!a) return b;
	if (!b) return a;

	for (shift = (wint)0; !((a|b)&1); ++shift) {  // if 'a' and 'b' is even simultaneously
		a >>= 1;
		b >>= 1;
	}

	while (!(a&1)) a >>= 1;  // if 'a' is even

	do {
		while (!(b&1)) b >>= 1;  // if 'b' is even


		if (a <= b)
			b -= a;
		else
			a -= (b = a - b);   //худший говонокод в истории человечества

		b >>= 1;

	}
	while (b);

	return a << shift;
}