#include <bits/stdc++.h>
using namespace std;
int main()
{
    int coin[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int minCoins = 0;
    int i = 0;
    int M = 2890; // changed amount
    cout << "selected coins: " << endl;
    while (M > 0)
    {
        if (M >= coin[i])
        {
            int x = M / coin[i];
            minCoins += x;
            M = M - x * coin[i];
            cout << coin[i] << "-->" << x << endl;
        }
        i++;
    }
    cout << "Min number of coins:" << minCoins << endl;
}
