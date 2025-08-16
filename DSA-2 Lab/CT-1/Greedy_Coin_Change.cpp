#include <bits/stdc++.h>
using namespace std;

vector<int> greedyCoinChange(int amount, vector<int> &coins)
{
    vector<int> result;
    sort(coins.rbegin(), coins.rend());
    for (int coin : coins)
    {
        while (amount >= coin)
        {
            amount -= coin;
            result.push_back(coin);
        }
    }

    return result;
}

int main()
{
    vector<int> coins = {1, 5, 10, 25};
    int amount = 63;

    vector<int> usedCoins = greedyCoinChange(amount, coins);

    cout << "Coins used: ";
    for (int c : usedCoins)
        cout << c << " ";
    cout << endl;

    return 0;
}
