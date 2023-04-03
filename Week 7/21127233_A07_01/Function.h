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
};

struct List {
    Node* pHead;
};

Node* CreateNode(int value);
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


#endif // !FUNCTION_H


