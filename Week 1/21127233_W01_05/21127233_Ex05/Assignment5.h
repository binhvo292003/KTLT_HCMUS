#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
	string _id;
	string _name;
	float _gpa;

	void Input(string id, string name, float gpa);
};

Student FindHighestGpa(string file);