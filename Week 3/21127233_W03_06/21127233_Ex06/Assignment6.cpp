#include "Assignment6.h"


int* MakeRandomArr(const int& n) {
	int* arr = new int[n];

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % 100;
	}

	return arr;
}

int* CreateArrDoubleSize(int* arr, const int& n) {
	int newSize = 2 * n;
	int* newArr = new int[newSize];

	for (int i = 0; i < n; i++) {
		newArr[i] = arr[i];
	}

	for (int i = n; i < newSize; i++) {
		newArr[i] = 0;
	}

	return newArr;
}
