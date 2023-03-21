#include <iostream>

#include "Function.h"

using namespace std;

int main() {
	SinhVien* student;
	int n;
	
	cout << "Nhap so sinh vien: "; cin >> n;
	student = new SinhVien[n];

	cout << "______________________________" << endl;
	cout << "Input" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien " << i << ": " << endl;
		Input(student[i]);
	}

	cout << "______________________________" << endl;
	cout << "Output" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien " << i << ": " << endl;
		Output(student[i]);
	}

	cout << "______________________________" << endl;
	cout << "Check ID valid" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien " << i << ": " << endl;
		cout << student[i].mssv;
		if (IsIdValid(student[i])) {
			cout << " valid" << endl;
		}
		else {
			cout << " invalid" << endl;
		}
	}
	cout << "______________________________" << endl;
	cout << "Rewrite name" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien " << i << ": " << endl;
		RewriteName(student[i]);
		Output(student[i]);
	}

	delete[] student;
}

