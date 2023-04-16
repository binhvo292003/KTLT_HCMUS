#include "Recursion3.h"

bool isPalindrome(int l, int r, string s) {
    if (r - l == 1 || l == r)
    {
        return 1;
    }
    else
    {
        if (s[l] == s[r])
        {
            return isPalindrome(l + 1, r - 1, s);
        }
        else
        {
            return 0;
        }
    }
}