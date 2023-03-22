#include <iostream>

#include "Function.h"

using namespace std;

int main() {
	SinhVien* student;
	int n;

	student = new SinhVien();

	cout << "______________________________" << endl;
	cout << "Input" << endl;
	cout << "Sinh vien: " << endl;
	Input(*student);


	cout << "______________________________" << endl;
	cout << "Output" << endl;
	cout << "Sinh vien: " << endl;
	Output(*student);

	cout << "______________________________" << endl;
	cout << "Check ID valid" << endl;
	cout << "Sinh vien: " << endl;
	cout << student->mssv;
	if (IsIdValid(*student)) {
		cout << " valid" << endl;
	}
	else {
		cout << " invalid" << endl;
	}

	cout << "______________________________" << endl;
	cout << "Rewrite name" << endl;
	cout << "Sinh vien: " << endl;
	RewriteName(*student);
	Output(*student);

	cout << "______________________________" << endl;
	cout << "Check sub string in name" << endl;
	cout << "Sub str: Abc" << endl;

	cout << "Sinh vien: " << endl;
	if (CheckContain(*student, "Abc")) {
		cout << "Sub string exist" << endl;
	}
	else {
		cout << "Sub string not exist" << endl;
	}


	SinhVien* listStudent;
	cout << "______________________________" << endl;
	cout << "Input list student" << endl;
	cout << "Nhap so sinh vien: "; cin >> n;
	listStudent = ListStudent(n);


	cout << "______________________________" << endl;
	cout << "Desc avg student" << endl;
	HighAVG(listStudent, n);
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien " << i << ": " << endl;
		Output(listStudent[i]);
	}

	delete[] listStudent;
	delete[] student;
}

