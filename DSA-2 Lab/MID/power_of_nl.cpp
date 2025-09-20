#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n)
{
    if (n <= 0)
    {
        return false;
    }

    // Keep dividing n by 4
    while (n % 4 == 0)
    {
        n /= 4;
    }

    return n == 1;
}

int main()
{
    int n;
    cin >> n;

    if (isPowerOfFour(n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
