#include <iostream>
#include "StackLL.h"

using namespace std;

int main() {
    Stack s;
    int n = 10;
    init(s, n);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    cout << pop(s) << " popped from stack\n";


    cout << "Stack Data : ";
    while (!isEmpty(s)) {
        cout << peek(s) << " ";
        pop(s);
    }

    if (isEmpty(s)) {
        cout << "\nEmpty!!!\n";
    }
    else {
        cout << "\nNot empty!!!\n";
    }

    cout << "Size of stack: " << size(s);

    return 0;

}