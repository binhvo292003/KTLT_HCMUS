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
bool CheckContain(SinhVien& a,const char* subStr);
char* substr(char* str, int begin, int len);
SinhVien* ListStudent(const int& n);
void HighAVG(SinhVien* list, const int& n);
void Swap(SinhVien& a, SinhVien& b);


#endif // !FUNCTION_H
