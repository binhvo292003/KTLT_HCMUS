#include <iostream>

#include "Assignment6.h"

using namespace std;

int main() {
	int size;

	cout << "Input size of arr: ";
	cin >> size;

	int* arr = MakeRandomArr(size);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int* newArr = CreateArrDoubleSize(arr, size);
	for (int i = 0; i < size * 2; i++) {
		cout << newArr[i] << " ";
	}

	delete[] arr;
	delete[] newArr;
	return 0;
}