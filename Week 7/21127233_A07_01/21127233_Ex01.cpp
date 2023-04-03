#include <iostream>

#include "Function.h"

int main() {
	List l;
    Node* pHead = NULL;

    /*int n;
    cout << "Nhap so luong Node: "; cin >> n;

    int tmp;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        cin >> tmp;
        AddTail(pHead, CreateNode(tmp));
    }*/



    cout << "\n3.1\n";
    pHead = LinkedListFromTxt("input.txt");
    PrintList(pHead);
    cout << endl;

    int valueX;
    cout << "Enter value x: "; cin >> valueX;
    RemoveX(pHead, valueX);
    PrintList(pHead);
    LinkedListToTxt("output.txt", pHead);

    return 0;

}
