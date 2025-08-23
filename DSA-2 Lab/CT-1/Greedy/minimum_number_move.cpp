#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int moves = 0;

    for (int i = 0; i < n;)
    {
        if (i + 1 < n && arr[i + 1] - arr[i] <= 2)
        {
            moves++;
            i += 2;
        }
        else
        {
            moves++;
            i++;
        }
    }
    return moves;
}

int main()
{
    vector<int> A = {1, 3, 5, 9};
    cout << minMoves(A) << "\n";
    return 0;
}
