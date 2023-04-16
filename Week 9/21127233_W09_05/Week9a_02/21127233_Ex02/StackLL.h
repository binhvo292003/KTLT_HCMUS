#ifndef STACKLL_H
#define STACKLL_H
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

struct Stack {
	Node* head;
	int capacity;
};

void init(Stack& s, int capacity);	// : create an empty stack.
void push(Stack& s, int x); // : add an integer to stack. 
int pop(Stack& s); // : remove the top element from stack, return the value of the removed one.
bool isEmpty(Stack& s); // : check whether a stack is empty or not.
void empty(Stack& s); // : make a stack empty.
int size(Stack& s); //	: get the number of elements in the stack.
int peek(Stack& s);
Node* CreateNode(int value);
void AddHead(Node*& pHead, Node* p);
void AddTail(Node*& pHead, Node* p);
void RemoveHead(Node*& pHead);
int RemoveTail(Node*& pHead);
int countNode(Node*& pHead);
int GetNodeAtTail(Node*& pHead);

#endif // !STACKLL_H
