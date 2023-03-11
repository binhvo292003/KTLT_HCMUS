#include <stdio.h>
#include <iostream>

#include "Assignment2.h"

using namespace std;

int main()
{
	Student* arrStu;

	int size;

	cout << "Input number of students: ";
	cin >> size;

	arrStu = InputNStudent(size);
	OutputNStudent(arrStu, size);

	cout << "\n----------------------------------\n";
	cout << "\nStudent less than 5:\n";
	int nLessThan5 = AmountLessThan5(arrStu, size);
	Student* stuLessThan5 = StuLessThan5(arrStu, size);
	OutputNStudent(stuLessThan5, nLessThan5);

	cout << "\n----------------------------------\n";
	cout << "\nAsc Id:\n";
	SortByAscID(arrStu, size);
	OutputNStudent(arrStu, size);

	cout << "\n----------------------------------\n";
	cout << "\nDesc Name:\n";
	SortByDescName(arrStu, size);
	OutputNStudent(arrStu, size);

	cout << "\n----------------------------------\n";
	cout << "\nTop 3 Score:\n";
	OutputTop3(arrStu, size);

	delete[] arrStu;

	return 0;
}