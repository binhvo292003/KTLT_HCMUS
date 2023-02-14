#include "Assignment1.h"

void PhanSo::Input(int tu, int mau) {
	_tu = tu;
	_mau = mau;
}

void SwapFrac(PhanSo& a, PhanSo& b) {
	PhanSo tmp;
	tmp.Input(a._tu, a._mau);
	a.Input(b._tu, b._mau);
	b.Input(tmp._tu, tmp._mau);
}

void SortFracFromTxtFile(string file) {
	fstream ifs;
	ifs.open(file);

	string s;
	getline(ifs, s);
	int n;
	n = stoi(s);
	cout << n << endl;

	PhanSo* res = new PhanSo[n];

	int tu, mau;
	int i = 0;
	while (!ifs.eof()) {
		getline(ifs, s, ' ');
		tu = stoi(s);
		getline(ifs, s);
		mau = stoi(s);
		res[i].Input(tu, mau);
		cout << tu << " " << mau << endl;
		i++;
	}

	ifs.close();

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (res[i]._tu * res[j]._mau > res[j]._tu * res[i]._mau) {
				SwapFrac(res[i], res[j]);
			}
		}
	}

	
	ofstream ofs;
	ofs.open("output.txt", ios::out);

	ofs << n << endl;
	for (int i = 0; i < n; i++) {
		ofs << res[i]._tu << " " << res[i]._mau << endl;
	}

	ofs.close();
}