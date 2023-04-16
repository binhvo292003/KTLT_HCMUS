#include "StackLL.h"

void init(Stack& s, int capacity) {
	s.head = NULL;
	s.capacity = capacity;
}

void push(Stack& s, int x) {
	if (countNode(s.head) < s.capacity) {
		AddTail(s.head, CreateNode(x));
	}
	else {
		cout << "Stack full\n";
	}
}

int pop(Stack& s) {
	if (countNode(s.head) >= 0) {
		int tmp = RemoveTail(s.head);
		return tmp;
	}

	cout << "Stack empty\n";
	return 0;
}

bool isEmpty(Stack& s) {
	if (countNode(s.head) == -1) {
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
	int tmp = countNode(s.head) + 1;
	return tmp;
}

int peek(Stack& s) {
	if (countNode(s.head) < 0) {
		cout << "Stack Empty";
		return 0;
	}
	else {
		int x = GetNodeAtTail(s.head);
		return x;
	}
}

Node* CreateNode(int value) {
	Node* temp = new Node;
	temp->data = value;
	temp->next = NULL;

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
		p->next = pHead;
		pHead = p;
	}
}

void AddTail(Node*& pHead, Node* p) {
	if (CheckEmpty(pHead)) {//rỗng
		pHead = p;
	}
	else {
		//Tìm thằng cuối
		Node* temp = pHead;//node cuối là temp khi xong while
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = p;
	}
}

void RemoveHead(Node*& pHead) {
	if (pHead == NULL) {
		return;
	}
	else if (pHead->next == NULL) {
		delete[] pHead;
		pHead = NULL;
		return;
	}

	Node* tmp;
	tmp = pHead;
	pHead = pHead->next;
	delete[] tmp;
	tmp = NULL;
	return;
}

int RemoveTail(Node*& pHead) {
	if (pHead == NULL)
		return 0;

	if (pHead->next == NULL) {
		delete pHead;
		pHead = NULL;
		return 0;
	}

	Node* second_last = pHead;
	int tmp = 0;
	while (second_last->next->next != NULL) {
		second_last = second_last->next;
	}
	tmp = second_last->next->data;
	delete[] second_last->next;
	second_last->next = NULL;
	return tmp;
}

int countNode(Node*& pHead) {
	int n = -1;
	Node* temp = pHead;
	while (temp != NULL) {
		temp = temp->next;
		n++;
	}
	return n;
}

int GetNodeAtTail(Node*& pHead) {
	Node* temp = pHead;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	return temp->data;
}
