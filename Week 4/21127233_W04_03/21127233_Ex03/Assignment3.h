#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

#include <iostream>

using namespace std;

struct Seat {
	char status = '#';
	int price;
	
};

Seat** CreateTheater(const int& rows, const int& columns);
void ShowChart(Seat** theater, const int& rows, const int& columns);
int* PriceEachRow(const int& rows);
int Menu();
void UpdatePrice(Seat** theater, int* price, const int& rows, const int& columns);

#endif // !ASSIGNMENT3_H
