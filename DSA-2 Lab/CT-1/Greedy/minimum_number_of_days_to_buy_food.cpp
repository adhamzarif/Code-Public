#include <bits/stdc++.h>
using namespace std;

int main()
{
    int S, N, M;
    cin >> S >> N >> M;

    int sundays = S / 7;
    int shopping_days = S - sundays;
    int total_food = S * M;

    if (shopping_days * N < total_food)
    {
        cout << -1 << endl;
    }
    else
    {
        int min_days = (total_food + N - 1) / N;
        cout << min_days << endl;
    }

    return 0;
}
