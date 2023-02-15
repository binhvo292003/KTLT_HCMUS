#include <iostream>
#include <fstream>
#include <string>

#define PI 3.14

using namespace std;

struct Circle {

	int _x;
	int _y;
	float _r;

	void Input(int x, int y,float r);
	float SumOfArea();
};

void CircleFromTxtFile(string file);