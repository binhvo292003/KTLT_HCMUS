#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct PhanSo{
	int _tu;
	int _mau;

	void Input(int tu, int mau);
};

void SwapFrac(PhanSo& a, PhanSo& b);

void SortFracFromTxtFile(string file);