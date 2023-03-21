#include "Function.h"

void Input(SinhVien& a) {
	char* tmp = new char[100];
	cout << "MSSV: ";
	cin >> a.mssv;
	cout << "Ho va ten: ";
	cin.ignore();
	cin.getline(tmp, 100);
	cout << "AVG: ";
	cin >> a.diemTB;

	a.ten = new char[strlen(tmp)];
	strcpy(a.ten, tmp);
	delete[] tmp;
}

void Output(SinhVien& a) {
	cout << "MSSV: " << a.mssv << endl;
	cout << "Ten: " << a.ten << endl;
	cout << "AVG: " << a.diemTB << endl;
}

bool IsIdValid(SinhVien& a) {
	if (a.mssv - 1000000 > 0 && a.mssv - 10000000 < 0) {
		return true;
	}
	return false;
}

void RewriteName(SinhVien& a) {
	//cout << strlen(a.ten);
	for (int i = 0; i < strlen(a.ten); i++) {
		//cout << a.ten[i];
		if (i == 0 || (i > 0 && a.ten[i - 1] == ' ')) {
			if (a.ten[i] >= 'a' && a.ten[i] <= 'z') {
				a.ten[i] -= ('a' - 'A');
			}
		}
		else {
			if (a.ten[i] >= 'A' && a.ten[i] <= 'Z') {
				a.ten[i] += ('a' - 'A');
			}
		}

	}
}


