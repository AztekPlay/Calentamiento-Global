#ifndef RATIONAL_H
#define RATIONAL_H


struct Rational;
typedef struct Rational Rational;


Rational* create(int numer, int denom);  // Allocates memory in the heap

int compare(Rational* a, Rational* b);

Rational* add(Rational* a, Rational* b);

Rational* sub(Rational* a, Rational* b);

Rational* mul(Rational* a, Rational* b);

Rational* adiv(Rational* a, Rational* b);

Rational* power(Rational* r, int power);
 
int RatToInt(Rational* r);  // Discards the fractional part

float RatToFloat(Rational* r);

char* RatToStr(Rational* r);  // Allocates memory in the heap 

#endif
