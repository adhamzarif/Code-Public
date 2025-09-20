#include <bits/stdc++.h>
using namespace std;

string removeSpaceToLower(const string &str, int index = 0)
{
    if (index == str.length())
    {
        return "";
    }

    char ch = str[index];
    if (ch == ' ')
    {
        return removeSpaceToLower(str, index + 1);
    }
    return string(1, tolower(ch)) + removeSpaceToLower(str, index + 1);
}

int main()
{
    cout << removeSpaceToLower("Hello World It's Me.") << endl;
}
