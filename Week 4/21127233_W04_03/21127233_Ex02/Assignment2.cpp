#include "Assignment2.h"

Student::Student() {
	Name = new char[100];
	Address = new char[100];
}

//Student::~Student() {
//	delete Name;
//	Name = nullptr;
//	delete Address;
//	Address = nullptr;
//}


void InputStudentData(Student*& student) {
	cout << "Id: ";
	cin >> student->Id;
	cin.ignore();
	cout << "Name: ";
	cin.getline(student->Name, SIZE_NAME);
	cout << "Score: ";
	cin >> student->Score;
	cin.ignore();
	cout << "Address: ";
	cin.getline(student->Address, SIZE_ADDRESS);
}

void InputStudentData(Student& student) {
	cout << "Id: ";
	cin >> student.Id;
	cin.ignore();
	cout << "Name: ";
	cin.getline(student.Name, SIZE_NAME);
	cout << "Score: ";
	cin >> student.Score;
	cin.ignore();
	cout << "Address: ";
	cin.getline(student.Address, SIZE_ADDRESS);
}

void OutputStudentData(Student*& student) {
	cout << "Id: ";
	cout << student->Id << endl;
	cout << "Name: ";
	cout << student->Name << endl;
	cout << "Score: ";
	cout << student->Score << endl;
	cout << "Address: ";
	cout << student->Address << endl;
}

void OutputStudentData(Student& student) {
	cout << "Id: ";
	cout << student.Id << endl;
	cout << "Name: ";
	cout << student.Name << endl;
	cout << "Score: ";
	cout << student.Score << endl;
	cout << "Address: ";
	cout << student.Address << endl;
}

Student* InputNStudent(int& size) {
	Student* arr = new Student[size];

	cout << "\nInput:\n";

	for (int i = 0; i < size; i++) {
		cout << "Student[" << i << "]:" << endl;
		InputStudentData(arr[i]);
		cout << endl;
	}

	return arr;
}

void OutputNStudent(Student* arr, int& size) {
	cout << "\nOutput:\n";

	for (int i = 0; i < size; i++) {
		cout << "Student[" << i << "]:" << endl;
		OutputStudentData(arr[i]);
		cout << endl;
	}
}

int AmountLessThan5(Student* arr, int& size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].Score < 5.0) {
			count++;
		}
	}
	return count;
}

Student* StuLessThan5(Student* arr, int& size) {
	int n = AmountLessThan5(arr, size);

	Student* res = new Student[n];

	for (int i = 0, j = 0; i < size; i++) {
		if (arr[i].Score < 5.0) {
			res[j] = arr[i];
			j++;
		}
	}

	return res;
}

void SortByAscID(Student*& arr, int& size) {
	Student tmp;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i].Id > arr[j].Id) {
				//Swap(arr[i], arr[j]);
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void SortByDescName(Student*& arr, int& size) {
	Student tmp;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (strcmp(arr[i].Name, arr[j].Name) < 0) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void SortByScore(Student*& arr, int& size) {
	Student tmp;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i].Score < arr[j].Score) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void OutputTop3(Student* arr, int& size) {
	SortByScore(arr, size);

	if (size < 3) {
		for (int i = 0; i < size; i++) {
			cout << "Student[" << i << "]:" << endl;
			OutputStudentData(arr[i]);
			cout << endl;
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		cout << "Student[" << i << "]:" << endl;
		OutputStudentData(arr[i]);
		cout << endl;
	}
}

