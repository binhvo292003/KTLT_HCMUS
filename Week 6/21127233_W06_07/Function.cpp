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

bool CheckContain(SinhVien& a, const char* sub) {
	int length = strlen(sub);
	int lengthStr = strlen(a.ten);

	char* subName;

	for (int i = 0; i < lengthStr - length + 1; i++) {
		subName = substr(a.ten, i, length);

		if (strcmp(sub, subName) == 0) {
			delete[] subName;
			return true;
		}
		delete[] subName;
	}

	return false;
}

char* substr(char* str, int begin, int len) {
	char* res = new char[len + 1];
	for (int i = 0; i < len; i++) {
		res[i] = str[begin + i];
	}
	res[len] = '\0';
	return res;
}

SinhVien* ListStudent(const int& n) {
	SinhVien* res = new SinhVien[n];

	cout << "Input" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien " << i << ": " << endl;
		Input(res[i]);
	}

	return res;
}

void HighAVG(SinhVien* list, const int& n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (list[i].diemTB < list[j].diemTB) {
				Swap(list[i], list[j]);
			}
		}
	}
}

void Swap(SinhVien& a, SinhVien& b) {
	SinhVien temp;
	temp = a;
	a = b;
	b = temp;
	return;
}


