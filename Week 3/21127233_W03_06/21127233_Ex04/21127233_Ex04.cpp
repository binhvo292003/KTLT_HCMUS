#include <iostream>
#include "Assignment4.h"

using namespace std;

int main() {
	int* arr;
	int size;

	cout << "Input size of arr: ";
	cin >> size;
	arr = MakeRandomArr(size);
	//cout << arr;
	for (int i = 0; i < size; i++) {
		cout <<arr[i] << " ";
	}
	cout << endl;

	cout << "Mode of arr: " << FindModeOfArray(arr, size);

	delete[] arr;
}