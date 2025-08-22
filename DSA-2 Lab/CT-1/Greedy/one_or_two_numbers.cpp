#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int> &A)
{
    sort(A.begin(), A.end());
    int moves = 0;
    int n = A.size();
    for (int i = 0; i < n;)
    {
        if (i + 1 < n && A[i + 1] - A[i] <= 2)
        {
            i += 2;
        }
        else
        {
            i += 1;
        }
        moves++;
    }
    return moves;
}

int main()
{
    vector<int> A = {1, 3, 5, 9};
    cout << minMoves(A) << endl;
    return 0;
}
