#include "Function.h"

Book* CreateBook(Book book) {
	Book* pBook = new Book();
	*pBook = book;
	pBook->pNext = NULL;
	return pBook;
}

void InputBook(Book* book) {
	cout << "Title: "; cin.getline(book->title, 200);
	//cin.ignore();
	cout << "ID: "; cin.getline(book->ID, 100);
	//cin.ignore();
	cout << "Author: "; cin.getline(book->author, 100);
	//cin.ignore();
	cout << "Language: "; cin.getline(book->language, 100);
	//cin.ignore();
	cout << "Year: "; cin >> book->year;
	cout << "Price: "; cin >> book->price;
	cout << "Stock level: "; cin >> book->stockLevel;
	cin.ignore();
}


void AddTailBookstore(Bookstore* bookstore, Book* book) {
	if (!bookstore->pHead) {
		bookstore->pHead = book;
		bookstore->pTail = book;
	}
	else {
		Book* temp = bookstore->pHead;
		while (temp != NULL) {
			if (!strcmp(temp->title, book->title) && !strcmp(temp->author, book->author)) {
				temp->stockLevel += book->stockLevel;
				return;
			}
			temp = temp->pNext;
		}
		bookstore->pTail->pNext = book;
		bookstore->pTail = book;
	}
}

void PrintBookstore(Bookstore* bookstore) {
	Book* temp = bookstore->pHead;
	cout << "\nPrint Bookstore\n";
	int i = 0;
	while (temp != NULL) {
		cout << "\nBook " << i++ << ": \n";
		cout << "Title: " << temp->title << endl;
		cout << "ID: " << temp->ID << endl;
		cout << "Author: " << temp->author << endl;
		cout << "Language: " << temp->language << endl;
		cout << "Year: " << temp->year << endl;
		cout << "Price: " << temp->price << endl;
		cout << "Stock level: " << temp->stockLevel << endl;
		temp = temp->pNext;
	}
}

void SellABook(Bookstore* bookstore, const char id[10]) {
	Book* temp = bookstore->pHead;
	int i = 0;
	while (temp != NULL) {
		if (!strcmp(id, temp->ID)) {
			if (temp->stockLevel == 0) {
				cout << "\nOut of stock!!!\n";
			}
			else {
				cout << "\Sell success!!!\n";
				temp->stockLevel--;
			}
			return;
		}
		temp = temp->pNext;
	}

	cout << "\nDont have that book\n";
}

bool CheckSub(const char* root, const char* sub) {
	int len = strlen(root);
	int lenSub = strlen(sub);

	char* subbuff;
	subbuff = new char[lenSub + 1];

	for (int i = 0; i <= len - lenSub; i++) {
		memcpy(subbuff, &root[i], lenSub);
		subbuff[lenSub] = '\0';
		if (!strcmp(subbuff, sub)) {
			return true;
		}
	}

	return false;
}

void FindBookTitleId(Bookstore* bookstore, const char* sub){
	Book* temp = bookstore->pHead;
	cout << "\nFind Title and Id\n";
	int i = 0;
	while (temp != NULL) {
		cout << "\n";
		if (CheckSub(temp->title, sub)) {
			cout << "Title: " << temp->title << endl;
			cout << "ID: " << temp->ID << endl;
		}
		temp = temp->pNext;
	}
}

void RemoveLessThanK(Bookstore* bookstore, int k) {
	Book* temp = bookstore->pHead;
	Book* prev = NULL;
	int i = 0;
	while (temp != NULL) {

		if (temp->stockLevel < k) {
			if (temp == bookstore->pHead && temp == bookstore->pTail) {
				Book* removeTemp = temp;
				delete removeTemp;
				bookstore->pHead = NULL;
				bookstore->pTail = NULL;
				continue;
			}
			else if (temp == bookstore->pHead) {
				Book* removeTemp = temp;
				temp = temp->pNext;
				delete removeTemp;
				bookstore->pHead = temp;
				continue;
			}
			else if (temp == bookstore->pTail) {
				delete[] prev->pNext;
				prev->pNext = NULL;
				bookstore->pTail = prev;
				break;

			}
			else {
				prev->pNext = temp->pNext;
				Book* removeTemp = temp;
				temp = temp->pNext;
				delete removeTemp;
				continue;
			}
		}
		prev = temp;
		temp = temp->pNext;
	}
}


