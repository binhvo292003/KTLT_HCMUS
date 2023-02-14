#include "Assignment2.h"

void Circle::Input(int x, int y, float r) {
	_x = x;
	_y = y;
	_r = r;
}

float Circle::SumOfArea() {
	return _r * _r * PI;
}

void CircleFromTxtFile(string file) {
	fstream ifs;
	ifs.open(file);

	string s;
	getline(ifs, s);
	int n;
	n = stoi(s);
	cout << n << endl;

	Circle* res = new Circle[n];

	int x, y;
	float r;
	int i = 0;

	while (!ifs.eof()) {
		getline(ifs, s, ' ');
		x = stoi(s);
		getline(ifs, s, ' ');
		y = stoi(s);
		getline(ifs, s);
		r = stof(s);
		res[i].Input(x, y, r);
		cout << x << " " << y << " " << r << endl;
		i++;
	}

	ifs.close();



	ofstream ofs;
	ofs.open("output.txt", ios::out);

	ofs << n << endl;
	for (int i = 0; i < n; i++) {
		ofs << res[i].SumOfArea() << endl;
	}

	ofs.close();
}