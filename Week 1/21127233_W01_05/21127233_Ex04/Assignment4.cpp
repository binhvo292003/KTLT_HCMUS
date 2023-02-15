#include "Assignment4.h"

void Product::Input(string id, string name, int stock, int price) {
	_id = id;
	_name = name;
	_stock = stock;
	_price = price;

	if (stock < 0) {
		_stock = 0;
	}
	if (price < 0) {
		_price = 0;
	}
}

void ProductFromTxtFile(string file) {
	fstream ifs;
	ifs.open(file);

	string s;
	getline(ifs, s);
	int n;
	n = stoi(s);
	cout << n << endl;

	Product* res = new Product[n];

	string id, name;
	int stock, price;
	int count = 0;

	while (!ifs.eof()) {
		getline(ifs, s);
		id = s;
		getline(ifs, s);
		name = s;
		getline(ifs, s);
		stock = stoi(s);
		getline(ifs, s);
		price = stoi(s);
		res[count].Input(id, name, stock, price);
		count++;
	}

	ifs.close();

	int total = 0;
	for (int i = 0; i < count; i++) {
		total += res[i]._price * res[i]._stock;
	}

	ofstream ofs;
	ofs.open("output.txt", ios::out);

	ofs << "Total money need to buy all products: " << total;

	ofs.close();

	delete[] res;
	res = nullptr;
}