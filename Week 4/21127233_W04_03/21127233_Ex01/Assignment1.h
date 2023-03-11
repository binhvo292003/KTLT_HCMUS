#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H

#include <iostream>

using namespace std;

struct Fraction {
	int num;
	int deno;
};

Fraction* InputFrac(const int& n);
int countNegativeFrac(Fraction* fracArr, const int& n);
Fraction* ExtractNegativeFrac(Fraction* fracArr, const int& n);
void OuputArray(Fraction* fracArr, const int& n);
Fraction SumOfFrac(Fraction* fracArr, const int& n);
Fraction Sum2Fraction(const Fraction& a, const Fraction& b);
Fraction SumOfPosFrac(Fraction* fracArr, const int& n);
int gcd(int a, int b);
void reduceFrac(Fraction& frac);

#endif // !1
