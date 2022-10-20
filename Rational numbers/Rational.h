#ifndef RATIONAL_H
#define RATIONAL_H


typedef struct Rational {
	int numer;
	int denom;
} Rational;


Rational* create(int numer, int denom);  // Allocates memory in the heap


int set(Rational* num, int numer, int denom);

void reduct(Rational* num);


int compare(Rational a, Rational b);

int add(Rational* res, Rational a, Rational b);

int sub(Rational* res, Rational a, Rational b);

int mul(Rational* res, Rational a, Rational b);

int division(Rational* res, Rational a, Rational b);

int power(Rational* res, Rational r, int power);

 
int RatToInt(Rational r);  // Discards the fractional part

float RatToFloat(Rational r);

int RatToStr(Rational r, char* str, size_t strSize);


#endif
