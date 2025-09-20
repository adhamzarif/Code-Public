#include <bits/stdc++.h>
using namespace std;

int FindFrequency(vector<int> &a, int low, int high, int target)
{
    if (low == high)
    {
        if (a[low] == target)
        {
            return 1;
        }
        return 0;
    }

    int mid = (low + high) / 2;
    int l = FindFrequency(a, low, mid, target);
    int r = FindFrequency(a, mid + 1, high, target);

    return l + r;
}

int main()
{
    vector<int> v = {12, 8, 16, 9, 8, 8};
    int n = v.size();
    int t = 8;

    int c = FindFrequency(v, 0, n - 1, t);
    cout << c << endl;
}
