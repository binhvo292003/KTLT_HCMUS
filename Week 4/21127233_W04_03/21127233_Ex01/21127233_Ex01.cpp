#include <iostream>
#include "Assignment1.h"

using namespace std;

int main()
{
	int n = 0;
	cout << "Input n of Array: ";
	cin >> n;
	
	Fraction* arr = InputFrac(n);

	OuputArray(arr, n);

	Fraction* negArr = ExtractNegativeFrac(arr, n);
	
	int nNeg = countNegativeFrac(arr, n);
	cout << "Negative Array:" << endl;
	OuputArray(negArr, nNeg);

	Fraction sum = SumOfPosFrac(arr, n);
	cout << "SumPosFrac = " << sum.num << "/" << sum.deno;

	//system("pause");

	delete[] arr;
}
