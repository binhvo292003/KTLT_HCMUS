#include "Assignment5.h"

void Student::Input(string id, string name, float gpa) {
	_id = id;
	_name = name;
	_gpa = gpa;
}


Student FindHighestGpa(string file) {
	fstream ifs;
	ifs.open(file);

	string s;
	getline(ifs, s);
	int n;
	n = stoi(s);

	Student* res = new Student[n];

	string id, name;
	float gpa;
	int count = 0;

	while (!ifs.eof()) {
		getline(ifs, s);
		id = s;
		getline(ifs, s);
		name = s;
		getline(ifs, s);
		gpa = stof(s);
		res[count].Input(id, name, gpa);
		count++;
	}

	ifs.close();
	Student maxGpa = res[0];

	for (int i = 0; i < count; i++) {
		if (maxGpa._gpa < res[i]._gpa) {
			maxGpa = res[i];
		}
		else if (maxGpa._gpa = res[i]._gpa) {
			if (maxGpa._id > res[i]._id) {
				maxGpa = res[i];
			}
		}
	}

	delete[] res;
	res = nullptr;

	return maxGpa;
}
