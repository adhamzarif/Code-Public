#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int countVowels(string &s, int l, int r)
{
    if (l == r)
    {
        return isVowel(s[l]) ? 1 : 0;
    }

    int mid = (l + r) / 2;

    int leftCount = countVowels(s, l, mid);
    int rightCount = countVowels(s, mid + 1, r);

    return leftCount + rightCount;
}

int main()
{
    string s = "DivideAndConquer";
    int total = countVowels(s, 0, s.size() - 1);

    cout << "Total vowels = " << total << "\n";

    return 0;
}
