#include "Assignment3.h"

void Date::Input(int day, int month, int year) {
	if (IsDateValid(day, month, year)) {
		_day = day;
		_month = month;
		_year = year;
	}
}

bool IsLeap(int year){
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		return true;
	}
	return false;
}

int DayInMonth(int month, int year){
	int nNumOfDays;

	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (IsLeap(year)){
			return 29;
		}
		else{
			return 28;
		}
	}
}

bool IsDateValid(int day, int month, int year){
	// Year valid ?
	if (year < 0){
		return false; 
	}

	// Month valid ?
	if (month < 1 || month > 12)
	{
		return false;
	}

	// Day valid ?
	if (day < 1 || day > DayInMonth(month, year))
	{
		return false;
	}

	return true;
}

bool DateAGreaterB(Date a, Date b) {
	if (a._year > b._year) {
		return true;
	}
	if (a._year == b._year) {
		if (a._month > b._month) {
			return true;
		}
		else if (a._month == b._year) {
			if (a._day > b._day) {
				return true;
			}
		}
	}

	return false;
}

void SwapDate(Date& a, Date& b) {
	Date tmp;

	tmp.Input(a._day, a._month, a._year);
	a.Input(b._day, b._month, b._year);
	b.Input(tmp._day, tmp._month, tmp._year);
}

void DateFromTxtFile(string file) {
	fstream ifs;
	ifs.open(file);

	string s;
	getline(ifs, s);
	int n;
	n = stoi(s);
	cout << n << endl;

	Date* res = new Date[n];

	int day, month, year;
	int count = 0;

	while (!ifs.eof()) {
		getline(ifs, s, ' ');
		year = stoi(s);
		getline(ifs, s, ' ');
		month = stoi(s);
		getline(ifs, s);
		day = stof(s);
		if (IsDateValid(day, month, year)) {
			res[count].Input(day, month, year);
			cout << res[count]._year << " " << res[count]._month << " " << res[count]._day << endl;
			count++;
		}
	}

	ifs.close();

	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (DateAGreaterB(res[i], res[j])) {
				SwapDate(res[i], res[j]);
			}
		}
	}	

	ofstream ofs;
	ofs.open("output.txt", ios::out);

	ofs << count << endl;
	for (int i = 0; i < count; i++) {
		ofs << res[i]._year << " " << res[i]._month << " " << res[i]._day << endl;
	}

	ofs.close();

	delete[] res;
	res = nullptr;
}