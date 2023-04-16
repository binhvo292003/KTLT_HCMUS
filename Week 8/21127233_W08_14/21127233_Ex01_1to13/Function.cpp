#include "Function.h"

using namespace std;

Node* CreateNode(int value) {
	Node* temp = new Node;
	temp->data = value;
	temp->pNext = NULL;

	return temp;
}

Node* CreateLinkedList() {
	Node* pRoot = NULL;

	cout << "Input\n";
	cout << "0 to end list\n";
	int n;
	while (cin >> n) {
		AddTail(pRoot, CreateNode(n));
		PrintList(pRoot);
		cout << endl;
		if (n == 0) {
			break;
		}
	}

	return pRoot;
}

Node* CreateLinkedList1() {
	Node* pRoot = NULL;

	cout << "Input\n";
	cout << "-1 to end list\n";
	int n;
	while (cin >> n) {
		AddTail(pRoot, CreateNode(n));
		PrintList(pRoot);
		cout << endl;
		if (n == -1) {
			break;
		}
	}

	return pRoot;
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

void RemoveDuplicate(Node*& pHead) {
	Node* temp;

	temp = pHead;
	int counter = 0;
	while (temp != NULL) {
		RemoveX(temp->pNext, temp->data);
		temp = temp->pNext;
	}
}

void ReverseList(Node*& pHead) {
	Node* cur = pHead;
	Node* prev = NULL, * next = NULL;

	// 1 2 3 4 null

	while (cur != NULL) {
		next = cur->pNext;
		cur->pNext = prev;
		prev = cur;
		cur = next;
	}

	pHead = prev;

	RemoveHead(pHead);
	AddTail(pHead, CreateNode(0));
}

void AddEven(Node** pHead) {
	Node* cur = *pHead;
	Node* prev = NULL;

	int num = 2;
	AddHead(*pHead, CreateNode(num));

	while (cur->pNext != NULL) {
		prev = cur;
		num += 2;
		Node* node = CreateNode(num);
		node->pNext = prev->pNext;
		prev->pNext = node;

		cur = cur->pNext;
		cur = cur->pNext;
	}
}

void SortedList(Node** pHead, int n) {
	Node* cur = *pHead;
	int len = 0;

	while (cur->pNext != NULL) {
		if (n >= cur->data && n <= cur->pNext->data) {
			Node* node = CreateNode(n);
			node->pNext = cur->pNext;
			cur->pNext = node;
			return;
		}
		else if (n >= cur->data && cur->pNext->data == 0) {
			Node* node = CreateNode(n);
			node->pNext = cur->pNext;
			cur->pNext = node;
			return;
		}
		cur = cur->pNext;
	}


}

Node* ListOfSum(Node*& pHead) {
	Node* ListSum = NULL;
	Node* cur = pHead;
	Node* curSum = pHead;

	AddTail(ListSum, CreateNode(cur->data));
	curSum = ListSum;
	while (cur->pNext != NULL) {
		cur = cur->pNext;

		Node* node = CreateNode(curSum->data + cur->data);
		node->pNext = curSum->pNext;
		curSum->pNext = node;
		curSum = curSum->pNext;

		//AddTail(ListSum, CreateNode(curSum->data + cur->data));
	}
	curSum->data = 0;

	return ListSum;
}

void SplitTwoList(Node** pRoot, Node** lEven, Node** lOdd) {
	Node* cur = *pRoot;
	(*lEven) = (*pRoot)->pNext;
	(*lOdd) = (*pRoot);
	Node* curEven = *lEven;
	Node* curOdd = *lOdd;

	int turn = 0;
	cur = cur->pNext->pNext;
	while (cur != NULL) {
		if (cur->data == 0) {
			curEven->pNext = cur;
			curOdd->pNext = cur;
			break;
		}

		if (turn) {
			curEven->pNext = cur;
			curEven = curEven->pNext;
			turn = 0;
		}
		else {
			curOdd->pNext = cur;
			curOdd = curOdd->pNext;
			turn = 1;
		}
		cur = cur->pNext;
	}
}

void MergeTwoList(Node** lOdd, Node** lEven)
{
	Node* temp = NULL;
	Node* firstRef = *lOdd;
	Node* secondRef = *lEven;

	temp = firstRef;
	firstRef = firstRef->pNext;

	while (1)
	{
		if (firstRef->pNext == NULL) {
			temp->pNext = secondRef;
			break;
		}
		else if (secondRef->pNext == NULL) {
			temp->pNext = firstRef;
			break;
		}
		temp->pNext = secondRef;
		secondRef = secondRef->pNext;
		temp = temp->pNext;

		temp->pNext = firstRef;
		firstRef = firstRef->pNext;
		temp = temp->pNext;
	}
}

void JoinTwoList(Node** lOdd, Node** lEven) {
	Node* firstRef = *lOdd;
	Node* temp = *lOdd;
	firstRef = firstRef->pNext;

	while (firstRef->pNext != NULL) {
		temp->pNext = firstRef;
		firstRef = firstRef->pNext;
		temp = temp->pNext;
		
	}

	temp->pNext = *lEven;
}

int ListToInteger(Node* pRoot) {
	int res = 0;
	int powNum = 1;

	Node* cur = pRoot;

	while (cur->pNext != NULL) {
		res = res * 10 + cur->data;
		cur = cur->pNext;
	}
	return res;
}

Node* IntegerToList(int num) {
	Node* res = NULL;
	int temp;

	while (num != 0) {
		temp = num % 10;
		AddHead(res, CreateNode(temp));
		num /= 10;
	}

	AddTail(res, CreateNode(-1));
	return res;
}

void CreateIntersectionNode(Node** list1, Node** list2) {
	Node* temp1 = *list1;

	while (temp1->pNext->pNext != NULL) {
		temp1 = temp1->pNext;
	}
	
	Node* temp2 = *list2;
	while (temp2->pNext->pNext != NULL) {
		temp2 = temp2->pNext;
	}

	temp2->pNext = temp1;
}

Node* FindShareNode(Node* list1, Node* list2) {
	while (list2) {
		Node* temp = list1;
		while (temp) {
			if (temp == list2)
				return list2;
			temp = temp->pNext;
		}
		list2 = list2->pNext;
	}
	return NULL;
}

void CreateLoopNode(Node** pNode) {
	Node* cur = *pNode;
	Node* prev = *pNode;
	
	while (cur->pNext != NULL) {
		cur = cur->pNext;
	}

	prev = prev->pNext;

	cur->pNext = prev;
}

bool FindNodeLoop(Node* pRoot) {
	while (pRoot != NULL) {
		if (pRoot->flag == 1)
			return true;
		pRoot->flag = 1;

		pRoot = pRoot->pNext;
	}

	return false;
}



