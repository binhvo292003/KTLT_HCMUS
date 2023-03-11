#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

#include <iostream>
#include <string.h>

#define SIZE_NAME 50
#define SIZE_ADDRESS 100

using namespace std;

struct Student {
	int Id;
	char* Name;
	double Score;
	char* Address;

	Student();
	//~Student();
};

void InputStudentData(Student*& student);
void InputStudentData(Student& student);
void OutputStudentData(Student*& student);
void OutputStudentData(Student& student);
Student* InputNStudent(int& size);
void OutputNStudent(Student* arr, int& size);
int AmountLessThan5(Student* arr, int& size);
Student* StuLessThan5(Student* arr, int& size);
void SortByAscID(Student*& arr, int& size);
void SortByDescName(Student*& arr, int& size);
void SortByScore(Student*& arr, int& size);
void OutputTop3(Student* arr, int& size);

#endif // !ASSIGNMENT2_H
