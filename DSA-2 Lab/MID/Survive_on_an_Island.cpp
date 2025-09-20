#include <bits/stdc++.h>
using namespace std;

int main()
{
    int S, N, M;
    cin >> S >> N >> M;

    int total_food_needed = S * M;
    int sundays = S / 7;
    int open_days = S - sundays;

    if (total_food_needed > open_days * N)
    {
        cout << -1 << endl; // impossible to survive
    }
    else
    {
        int min_days = (total_food_needed + N - 1) / N; // ceil division
        cout << min_days << endl;
    }
}
