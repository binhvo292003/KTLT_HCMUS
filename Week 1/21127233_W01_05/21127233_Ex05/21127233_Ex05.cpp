#include <iostream>
#include "Assignment5.h"

int main(){
	Student res = FindHighestGpa("input.txt");
	
	cout << "Highest GPA:" << endl;
	cout << res._id << endl;
	cout << res._name << endl;
	cout << res._gpa << endl;

}
