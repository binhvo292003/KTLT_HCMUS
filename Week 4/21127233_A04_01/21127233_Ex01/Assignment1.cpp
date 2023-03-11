#include "Assignment1.h"

Fraction* InputFrac(const int& n) {
	Fraction* res = new Fraction[n];

	for (int i = 0; i < n; i++) {
		cout << "Frac[" << i << "]:" << endl;
		cout << "Numorator: "; cin >> res[i].num;
		cout << "Denominator: "; cin >> res[i].deno;

		if (res[i].deno == 0) {
			res[i].num = 0;
			res[i].deno = 1;
		}
		else if (res[i].num < 0 && res[i].deno < 0) {
			res[i].num *= (-1);
			res[i].deno *= (-1);
		}
		else if (res[i].num > 0 && res[i].deno < 0) {
			res[i].num *= (-1);
			res[i].deno *= (-1);
		}

		reduceFrac(res[i]);
	}

	return res;
}

int countNegativeFrac(Fraction* fracArr, const int& n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (fracArr[i].num < 0) {
			count++;
		}
	}
	return count;
}

Fraction* ExtractNegativeFrac(Fraction* fracArr, const int& n) {
	//int count = countNegativeFrac(fracArr, n);
	int count = 0;

	Fraction* res = new Fraction[count];

	for (int i = 0; i < n; i++) {
		if (fracArr[i].num < 0) {
			res[count].num = fracArr[i].num;
			res[count].deno = fracArr[i].deno;
			count++;
		}
	}

	return res;
}

void OuputArray(Fraction* fracArr, const int& n) {
	for (int i = 0; i < n; i++) {
		cout << "Frac[" << i << "] = " << fracArr[i].num << "/" << fracArr[i].deno << endl;
	}
}

Fraction Sum2Fraction(const Fraction& a, const Fraction& b) {
	Fraction res;
	res.num = a.num * b.deno + b.num * a.deno;
	res.deno = a.deno * b.deno;
	return res;
}

Fraction SumOfPosFrac(Fraction* fracArr, const int& n) {
	Fraction sum;
	sum.num = 0;
	sum.deno = 1;
	for (int i = 0; i < n; i++) {
		if (fracArr[i].num > 0) {
			sum = Sum2Fraction(sum, fracArr[i]);
		}
	}
	reduceFrac(sum);

	return sum;
}

int gcd(int a, int b) {
	int tmp;
	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}

	if (a < 0) {
		return a * (-1);
	}
	return a;
}

void reduceFrac(Fraction& frac) {
	int gcdNum = gcd(frac.num, frac.deno);
	frac.num /= gcdNum;
	frac.deno /= gcdNum;
}