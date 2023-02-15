#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Date {
	int _day;
	int _month;
	int _year;

	void Input(int day, int month, int year);
};

void SwapDate(Date& a, Date& b);
void DateFromTxtFile(string file);
bool IsLeap(int year);
int DayInMonth(int month, int year);
bool IsDateValid(int day, int month, int year);
bool DateAGreaterB(Date a, Date b);