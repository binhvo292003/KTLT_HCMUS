#include <iostream>

#include "Function.h"

using namespace std;

int main() {
	List l;
	Node* pHead = NULL;

	cout << "\n3.1\n";
	pHead = LinkedListFromTxt("input.txt");
	PrintList(pHead);
	cout << endl;

	int valueX;
	cout << "Enter value x: "; cin >> valueX;
	RemoveX(pHead, valueX);
	PrintList(pHead);
	LinkedListToTxt("output.txt", pHead);
	cout << endl;

	cout << "\n3.2\n";
	pHead = LinkedListFromTxt("input.txt");
	PrintList(pHead);
	cout << endl;

	cout << "After remove duplicate:\n";
	RemoveDuplicate(pHead);
	PrintList(pHead);
	LinkedListToTxt("output.txt", pHead);
	cout << endl;

	cout << "\n3.3\n";
	pHead = LinkedListFromTxt("input.txt");
	PrintList(pHead);
	cout << endl;
	cout << "After reverse:\n";
	ReverseList(pHead);
	PrintList(pHead);
	LinkedListToTxt("output.txt", pHead);
	cout << endl;

	cout << "\n3.4\n";
	pHead = LinkedListFromTxt("input.txt");
	PrintList(pHead);
	cout << endl;
	cout << "After even number:\n";
	AddEven(&pHead);
	PrintList(pHead);
	LinkedListToTxt("output.txt", pHead);
	cout << endl;

	cout << "\n3.5\n";
	pHead = LinkedListFromTxt("input.txt");
	PrintList(pHead);
	cout << endl;
	cout << "Sorted List:\n";
	SortedList(&pHead, 12);
	PrintList(pHead);
	LinkedListToTxt("output.txt", pHead);
	cout << endl;


	cout << "\n3.6\n";
	pHead = LinkedListFromTxt("input.txt");
	PrintList(pHead);
	cout << endl;
	cout << "List of Sum:\n";
	Node* ListSum = ListOfSum(pHead);
	PrintList(ListSum);
	LinkedListToTxt("output.txt", ListSum);
	cout << endl;


	cout << "\n3.7\n";
	pHead = CreateLinkedList();
	PrintList(pHead);
	cout << endl;

	cout << "Split 2 linked list:\n";
	Node* ListEven = NULL;
	Node* ListOdd = NULL;

	SplitTwoList(&pHead, &ListEven, &ListOdd);
	PrintList(ListEven);
	cout << endl;
	PrintList(ListOdd);
	cout << endl;

	cout << "\n3.8\n";
	cout << "1st List\n";
	ListOdd = CreateLinkedList();
	cout << "2nd List\n";
	ListEven = CreateLinkedList();

	PrintList(ListOdd);
	cout << endl;
	PrintList(ListEven);
	cout << endl;

	cout << "Merge 2 linked list:\n";

	MergeTwoList(&ListOdd, &ListEven);
	PrintList(ListOdd);
	cout << endl;

	cout << "\n3.9\n";
	cout << "1st List\n";
	ListOdd = CreateLinkedList();
	cout << "2nd List\n";
	ListEven = CreateLinkedList();

	PrintList(ListOdd);
	cout << endl;
	PrintList(ListEven);
	cout << endl;

	cout << "Join 2 linked list:\n";

	JoinTwoList(&ListOdd, &ListEven);
	PrintList(ListOdd);
	cout << endl;

	cout << "\n3.10\n";
	pHead = CreateLinkedList1();
	PrintList(pHead);
	cout << endl;
	cout << "List to Interger:";
	int listToInteger = ListToInteger(pHead);
	cout << listToInteger;
	cout << endl;

	cout << "\n3.11\n";
	cout << "Input integer: ";
	int num;
	cin >> num;
	cout << "Interger to List: ";
	pHead = IntegerToList(num);
	PrintList(pHead);

	Node* List1 = NULL;
	Node* List2 = NULL;

	cout << "\n3.12\n";
	cout << "1st List\n";
	List1 = CreateLinkedList();
	cout << "2nd List\n";
	List2 = CreateLinkedList();

	PrintList(List1);
	cout << endl;
	PrintList(List2);
	cout << endl;
	CreateIntersectionNode(&List1, &List2);
	cout << "Share Node: " << FindShareNode(List1, List2)->data;
	cout << endl;

	cout << "\n3.13\n";
	pHead = CreateLinkedList();
	PrintList(pHead);
	cout << endl;
	CreateLoopNode(&pHead);
	if (FindNodeLoop(pHead)) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;

}
