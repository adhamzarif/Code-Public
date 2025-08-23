#include <bits/stdc++.h>
using namespace std;

int main()
{
    int S, N, M;
    cin >> S >> N >> M;

    int total_required = S * M;

    int max_possible = (S - S / 7) * N;

    if (M > N || total_required > max_possible)
    {
        cout << -1 << "\n";
    }
    else
    {
        int min_days = (total_required + N - 1) / N;
        cout << min_days << "\n";
    }

    return 0;
}
