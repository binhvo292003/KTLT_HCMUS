#ifndef STACKARR_H
#define STACKARR_H
#include <iostream>

using namespace std;

struct Stack {
	int* data; // dynamic array
	int top; // index of top element
	int capacity; // size of stack
};

void init(Stack& s, int capacity);	// : create an empty stack.
void push(Stack& s, int x); // : add an integer to stack. 
int pop(Stack& s); // : remove the top element from stack, return the value of the removed one.
bool isEmpty(Stack& s); // : check whether a stack is empty or not.
void empty(Stack& s); // : make a stack empty.
int size(Stack& s); //	: get the number of elements in the stack.
int peek(Stack& s);

#endif // !STACKARR_H
