#include <iostream>
#include "Assignment5.h"

using namespace std;

int main() {
	int* arr;
	int size;

	cout << "Input size of arr: ";
	cin >> size;

	arr = MakeRandomArr(size);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Median of arr: " << FindMidOfArray(arr, size);

	return 0;
}