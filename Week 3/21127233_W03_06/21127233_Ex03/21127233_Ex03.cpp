#include <iostream>
#include "Assignment3.h"

using namespace std;

int main() {
	char pch[100]="1234321";
	
	if (isPalindrome(pch)) {
		cout << "Is palindrome";
	}
	else {
		cout << "Is not palindrome";
	}
}