#include <iostream>

#include "Assignment3.h"


#define ROWS 15
#define COLUMNS 30


using namespace std;

int main() {
	Seat** theater = CreateTheater(ROWS, COLUMNS);

	ShowChart(theater, ROWS, COLUMNS);

	int* price = PriceEachRow(ROWS);

	UpdatePrice(theater, price, ROWS, COLUMNS);

	int totalSeatAvailable = 450;
	int seatSell = 0;

	int rowBuy;
	int columnBuy;
	int flag;
	int choice;
	do
	{
		choice = Menu();

		switch (choice)
		{
		case 1:
			cout << "View Prices Each Row\n\n";
			for (int i = 0; i < ROWS; i++)
			{
				cout << "The price for row " << i << ": ";
				cout << price[i] << endl;
			}
			break;

		case 2:
			cout << "Buy a Ticket\n\n";

			do
			{
				cout << "Row you want to sit: ";
				cin >> rowBuy;
				cout << "Column you want to sit: ";
				cin >> columnBuy;

				if (theater[rowBuy][columnBuy].status == '*')
				{
					cout << "Sorry that seat is sold-out, Please select another seat.";
					cout << endl;
				}

				else
				{
					//	cost = price[row2] + 0;
					//	total = total + cost;
					cout << "That ticket costs: " << theater[rowBuy][columnBuy].price << endl;
					cout << "Confirm Purchase? Enter (1 = YES / 2 = NO)";
					cin >> flag;
					if (flag == 1)
					{
						cout << "Your ticket purchase has been confirmed." << endl;
						theater[rowBuy][columnBuy].status = '*';
						seatSell++;
						totalSeatAvailable--;
					}
				}

				cout << "Would you like to look at another seat?(1 = YES / 2 = NO)";
				cin >> flag;
				if (flag == 1) {
					continue;
				}
				else {
					break;
				}

			} while (true);

			break;

		case 3:
			cout << "View Available Seats\n\n";
			ShowChart(theater, ROWS, COLUMNS);
			break;

		case 4:
			cout << "View Ticket Sales\n\n";
			cout<<"Seat sell: " << seatSell << endl;
			cout << "Seat available: " << totalSeatAvailable << endl;
			break;

		case 5:
			cout << "Quit\n";
			break;

		default: cout << "Error input\n";
		}

	} while (choice != 5);

	for (int i = 0; i < ROWS; i++) {
		delete[] theater[i];
	}

	delete[] theater;
	delete[] price;

	return 0;
}