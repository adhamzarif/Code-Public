#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b; // sticks and diamonds

    int total = 0;

    if (a > b)
    {
        // make shovels first
        int shovels = min(a / 2, b);
        a -= 2 * shovels;
        b -= shovels;
        int swords = min(a, b / 2);
        total = shovels + swords;
    }
    else
    {
        // make swords first
        int swords = min(a, b / 2);
        a -= swords;
        b -= 2 * swords;
        int shovels = min(a / 2, b);
        total = swords + shovels;
    }

    cout << total << endl;
}
