#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Product {
	string _id;
	string _name;
	int _stock;
	int _price;

	void Input(string id, string name, int stock, int price);
};

void ProductFromTxtFile(string file);