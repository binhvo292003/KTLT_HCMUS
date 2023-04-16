#include "Recursion1.h"

int Fibonacci(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Xn(int n) {
	if (n == 0) {
		return 1;
	}

	return Xn(n - 1) + Yn(n - 1);
}

int Yn(int n) {
	if (n == 0) {
		return 0;
	}

	return 3 * Xn(n - 1) + 2 * Yn(n - 1);
}

int x(int n, int i) {
	if (n == 0) return 1;
	if (i == n) return 0;
	return (n - i) * (n - i) * x(i, 0) + x(n, i + 1);
}


int C(int n, int k) {
	if (n == k || k == 0) {
		return 1;
	}
	//if (1 < k && k < n) {
		return C(n - 1, k) + C(n - 1, k - 1);
//	}

}
