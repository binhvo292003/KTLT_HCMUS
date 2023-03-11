#include "Assignment3.h"

Seat** CreateTheater(const int& rows, const int& columns) {
	Seat** theater = new Seat * [rows];
	for (int i = 0; i < rows; i++) {
		theater[i] = new Seat[columns];
	}

	return theater;
}

void ShowChart(Seat** theater, const int& rows, const int& columns) {
	cout << string(10, ' ');
	for (int i = 0; i < columns; i++) {
		cout << i % 10 << ' ';
	}
	cout << endl;
	
	for (int i = 0; i < rows; i++) {
		if (i < 10) {
			cout << "Row " << i << "     ";
			for (int j = 0; j < columns; j++) {
				cout << theater[i][j].status << ' ';
			}
			cout << endl;
		}
		else {
			cout << "Row " << i << "    ";
			for (int j = 0; j < columns; j++) {
				cout << theater[i][j].status << ' ';
			}
			cout << endl;
		}
	}
}


int* PriceEachRow(const int& rows) {
	int* price = new int[rows];

	for (int i = 0; i < rows; i++) {
		cout << "Please enter the price for row " << i << ": ";
		cin >> price[i];
	}

	return price;
}

void UpdatePrice(Seat** theater, int* price, const int& rows, const int& columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			theater[i][j].price = price[i];
		}
	}
}

int Menu() {
	int choice;
	cout << endl << endl;
	cout << " \tMENU\n";
	cout << " 1/ View Prices Each Row.\n";
	cout << " 2/ Buy a Ticket.\n";
	cout << " 3/ View Available Seats.\n";
	cout << " 4/ View Ticket Sales.\n";
	cout << " 5/ Quit the program.\n";
	cout << "______________________\n\n";
	cout << "Please enter your choice: ";
	cin >> choice;
	cout << endl << endl;
	return choice;
}