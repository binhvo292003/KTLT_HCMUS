#ifndef FUNCTION_H
#include <iostream>

using namespace std;

#define SIZE_TEN 50


struct SinhVien {
	int mssv;
	char* ten;
	float diemTB;
};

void Input(SinhVien& a);
void Output(SinhVien& a);
bool IsIdValid(SinhVien& a);
void RewriteName(SinhVien& a);

#endif // !FUNCTION_H
