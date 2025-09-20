#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int> A)
{
    sort(A.begin(), A.end());
    int moves = 0;
    int i = 0;
    int n = A.size();

    while (i < n)
    {
        if (i + 1 < n && abs(A[i + 1] - A[i]) <= 1)
        {
            // Remove pair in one move
            i += 2;
        }
        else
        {
            // Remove single element
            i += 1;
        }
        moves++;
    }
    return moves;
}

int main()
{
    vector<int> A = {1, 3, 5, 9};
    cout << minMoves(A) << endl; // Output: 3
}
