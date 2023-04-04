#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node* pNext;
    int flag;
};

struct List {
    Node* pHead;
    Node* PTail;
};

Node* CreateNode(int value);
Node* CreateLinkedList();
Node* CreateLinkedList1();
bool CheckEmpty(Node* pHead);
void AddHead(Node*& pHead, Node* p);
void AddHead(List& l, Node* p);
void AddTail(Node*& pHead, Node* p);
void PrintList(Node* pHead);
void PrintList(List l);


Node* LinkedListFromTxt(string path);
void LinkedListToTxt(string path, Node* pHead);

void RemoveHead(Node*& pHead);
void RemoveTail(Node*& pHead);
void RemoveX(Node*& pHead, int n);

void RemoveDuplicate(Node*& pHead);

void ReverseList(Node*& pHead);

void AddEven(Node** pHead);

void SortedList(Node** pHead, int n);

Node* ListOfSum(Node*& pHead);

void SplitTwoList(Node** pRoot, Node** lEven, Node** lOdd);

void MergeTwoList(Node** lOdd, Node** lEven);

void JoinTwoList(Node** lOdd, Node** lEven);

int ListToInteger(Node* pRoot);

Node* IntegerToList(int num);

void CreateIntersectionNode(Node** list1, Node** list2);
Node* FindShareNode(Node* list1, Node* list2);

void CreateLoopNode(Node** pNode);
bool FindNodeLoop(Node* pNode);

#endif // !FUNCTION_H


