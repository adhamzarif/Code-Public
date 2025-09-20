#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    } // base case
    return a * power(a, b - 1);
}

void printPower(int a, int b)
{
    int x = power(a, abs(b));
    cout << a << " to the power of " << b << ": ";
    if (b < 0)
    {
        cout << "1/" << x;
    } // symbolic fraction
    else
    {
        cout << x;
    }
    cout << endl;
}

int main()
{
    int a = 2, b = -5;
    printPower(a, b);
    return 0;
}
