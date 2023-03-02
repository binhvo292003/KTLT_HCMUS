#include "Assignment4.h"

void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int* MakeRandomArr(const int& n) {
    srand(time(NULL));

    int* arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        *(arr + i) = rand() % 1'000'000;
    }

    //cout << arr << endl;
    return arr;
}

void SortArr(int* arr, const int& n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n; j++) {
            if (*(arr + i) > *(arr + j)) {
                Swap(*(arr + i), *(arr + j));
            }
        }
    }
}

int FindModeOfArray(int* arr, const int& n) {
    SortArr(arr, n);
    int cur = *arr;
    int mode = cur;
    int count = 1;
    int countMode = 1;

    for (int i = 1; i < n; i++) {
        if (*(arr + i) == cur) {
            ++count;
        }
        else {
            if (count > countMode){
                countMode = count;
                mode = cur;
            }
            count = 1;
            cur = *(arr + i);
        }
    }

    return mode;
}

