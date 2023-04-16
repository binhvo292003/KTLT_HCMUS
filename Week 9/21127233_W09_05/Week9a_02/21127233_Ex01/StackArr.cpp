#include "StackArr.h"

void init(Stack& s, int capacity) {
	s.data = new int[capacity]; 
	s.top = -1;
	s.capacity = capacity;
}

void push(Stack& s, int x) {
	s.top++;
	if (s.top < s.capacity) {
		s.data[s.top] = x;
	}
	else {
		s.top--;
		cout << "Stack full\n";
	}
}

int pop(Stack& s) {
	if (s.top >= 0) {
		int tmp = s.data[s.top];
		s.data[s.top] = NULL;
		s.top--;
		return tmp;
	}
	
	cout << "Stack empty\n";
	return 0;
}

bool isEmpty(Stack& s) {
	if (s.top == -1) {
		return true;
	}
	return false;
}


void empty(Stack& s) {
	while (s.capacity >= 0) {
		pop(s);
	}
}


int size(Stack& s) {
	int tmp = s.top + 1;
	return tmp;
}

int peek(Stack& s){
	if (s.top < 0) {
		cout << "Stack Empty";
		return 0;
	}
	else {
		int x = s.data[s.top];
		return x;
	}
}
