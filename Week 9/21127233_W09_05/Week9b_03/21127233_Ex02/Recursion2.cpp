#include "Recursion2.h"

int toBinary(int x) {
	if (x == 0) {
		return 0;
	}
	return (x % 2 + 10 * toBinary(x / 2));
}

int sumOfDigits(int x) {
	if (x == 0) {
		return 0;
	}
	return (x % 10 + sumOfDigits(x / 10));
}