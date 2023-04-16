#include <iostream>

#include "Function.h"

using namespace std;

int main()
{
    //1
    Bookstore bookstore;
    
    //2
    cout << "AddBook" << endl;
    Book tempBook;
    for (int i = 0; i < 3; i++) {
        InputBook(&tempBook);
        AddTailBookstore(&bookstore, CreateBook(tempBook));
        cout << "-------\n";
    }

    PrintBookstore(&bookstore);

    //3
    cout << "\nSell Book\n";
    SellABook(&bookstore, "123");
    PrintBookstore(&bookstore);

    //4
    cout << "\nFind Book";
    FindBookTitleId(&bookstore, "123");

    //5
    cout << "\nRemove stock less than k:\n";
    int k;
    cout << "k: "; cin >> k;
    RemoveLessThanK(&bookstore, k);
    PrintBookstore(&bookstore);

}
