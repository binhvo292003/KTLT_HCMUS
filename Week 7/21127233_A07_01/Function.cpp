#include "Function.h"

using namespace std;

Node* CreateNode(int value) {
	Node* temp = new Node;
	temp->data = value;
	temp->pNext = NULL;

	return temp;
}

bool CheckEmpty(Node* pHead) {
	if (pHead == NULL)
		return true;
	return false;
}

void AddHead(Node*& pHead, Node* p) {
	if (CheckEmpty(pHead)) {//rỗng
		pHead = p;
	}
	else {
		p->pNext = pHead;
		pHead = p;
	}
}

void AddHead(List& l, Node* p) {
	if (CheckEmpty(l.pHead)) {//rỗng
		l.pHead = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void AddTail(Node*& pHead, Node* p) {
	if (CheckEmpty(pHead)) {//rỗng
		pHead = p;
	}
	else {
		//Tìm thằng cuối
		Node* temp = pHead;//node cuối là temp khi xong while
		while (temp->pNext != NULL) {
			temp = temp->pNext;
		}
		temp->pNext = p;
	}
}

void PrintList(Node* pHead) {
	Node* temp = pHead;
	while (temp != NULL) {
		//cout << temp->data << endl;
		cout << temp->data << " ";
		temp = temp->pNext;
	}
}

void PrintList(List l) {
	Node* temp = l.pHead;
	while (temp != NULL) {
		//cout << temp->data << endl;
		cout << temp->data << " ";
		temp = temp->pNext;
	}
}

Node* LinkedListFromTxt(string path) {
	ifstream fi;
	fi.open(path);
	if (!fi) {
		cout << "\nCant open file!!!\n";
		return NULL;
	}
	
	string s;
	getline(fi, s);
	stringstream ss(s);
	Node* pHead = NULL;

	while (!ss.eof()) {
		ss >> s;
		AddTail(pHead, CreateNode(stoi(s)));
	}

	fi.close();
	return pHead;
}

void LinkedListToTxt(string path, Node* pHead) {
	ofstream fo;
	fo.open(path);
	if (!fo) {
		cout << "\nCant open file!!!\n";
		return;
	}

	Node* temp = pHead;
	while (temp != NULL) {
		fo << temp->data << " ";
		temp = temp->pNext;
	}

	fo.close();
	return;
}


void RemoveHead(Node*& pHead) {
	if (pHead == NULL) {
		return;
	}
	else if (pHead->pNext == NULL) {
		delete[] pHead;
		pHead = NULL;
		return;
	}

	Node* tmp;
	tmp = pHead;
	pHead = pHead->pNext;
	delete[] tmp;
	tmp = NULL;
	return;
}

void RemoveTail(Node*& pHead) {
	if (pHead == NULL)
		return;

	if (pHead->pNext == NULL) {
		delete pHead;
		return;
	}

	Node* second_last = pHead;
	while (second_last->pNext->pNext != NULL) {
		second_last = second_last->pNext;
	}

	delete[] second_last->pNext;
	second_last->pNext = NULL;
	return;
}


void RemoveX(Node*& pHead, int n) {
	Node* temp = pHead;
	Node* prev = NULL;

	int pos = 0;

	while (temp != NULL) {
		if (temp->data == n) {
			if (pos == 0) {
				RemoveHead(pHead);
				temp = pHead;
			}
			else if (temp->pNext == NULL) {
				RemoveTail(pHead);
				return;
			}
			else {
				prev->pNext = prev->pNext->pNext;
				delete[] temp;
				temp = prev->pNext;
			}

			continue;
		}
		prev = temp;
		temp = temp->pNext;
		pos++;
	}
}

