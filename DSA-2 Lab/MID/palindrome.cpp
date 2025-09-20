#include <bits/stdc++.h>
using namespace std;

bool palindrome(const string &str, int left = 0, int right = -1)
{
    if (right == -1)
    {
        right = str.length() - 1;
    } // initialize right on first call
    if (left >= right)
    {
        return true;
    }
    if (str[left] != str[right])
    {
        return false;
    }
    return palindrome(str, left + 1, right - 1);
}

int main()
{
    string s = "abeeba";
    if (palindrome(s))
    {
        cout << "palindrome";
    }
    else
    {
        cout << "not palindrome";
    }
}
