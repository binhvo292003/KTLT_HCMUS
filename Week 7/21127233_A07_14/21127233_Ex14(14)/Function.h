#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>

using namespace std;

struct Book {
	char title[200];
	char ID[10];
	char author[40];
	char language[30];
	int year;
	double price;
	int stockLevel;

	Book* pNext;
};

struct Bookstore {
	Book* pHead = NULL;
	Book* pTail = NULL;
};

Book* CreateBook(Book book);
void InputBook(Book* book);
void AddTailBookstore(Bookstore* bookstore, Book* book);
void PrintBookstore(Bookstore* bookstore);
void SellABook(Bookstore* bookstore, const char id[10]);
bool CheckSub(const char* root, const char* sub);
void FindBookTitleId(Bookstore* bookstore, const char* sub);
void RemoveLessThanK(Bookstore* bookstore, int k);

#endif // !FUNCTION_H
