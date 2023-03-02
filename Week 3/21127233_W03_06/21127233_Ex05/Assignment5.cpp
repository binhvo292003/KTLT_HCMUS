#include "Assignment5.h"

void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int* MakeRandomArr(const int& n) {
	int* arr = new int[n];
	
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % 100;
	}

	return arr;
}

void SortArr(int* arr, const int& n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < n; j++) {
			if (*(arr + i) > *(arr + j)) {
				Swap(*(arr + i), *(arr + j));
			}
		}
	}
}

double FindMidOfArray(int* arr, int n) {
	double med = 0.0;

	med = *(arr + (n / 2));

	if (n % 2 == 0){
		med = (*(arr + ((n - 1) / 2)) + med) / 2.0;
	}
	
	delete[] arr;
	return med;
}