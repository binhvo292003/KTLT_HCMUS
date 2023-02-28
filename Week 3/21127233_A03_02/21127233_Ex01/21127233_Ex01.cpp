#include <iostream>

#include "Assignment1.h"

using namespace std;

int main() {
	int a = 6;
	int* ptrNum = &a;

	cout << a << endl;
	addOne(ptrNum);
	output(ptrNum);
	addOne(ptrNum);
	output(ptrNum);
}
