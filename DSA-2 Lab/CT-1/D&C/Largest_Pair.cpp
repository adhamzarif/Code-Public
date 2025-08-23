#include <bits/stdc++.h>
using namespace std;

pair<int, int> largestPair(vector<int> &arr, int l, int r)
{
    if (l == r)
    {
        return {arr[l], INT_MIN};
    }
    if (l + 1 == r)
    {
        if (arr[l] > arr[r])
        {
            return {arr[l], arr[r]};
        }
        else
        {
            return {arr[r], arr[l]};
        }
    }

    int mid = (l + r) / 2;

    pair<int, int> left = largestPair(arr, l, mid);
    pair<int, int> right = largestPair(arr, mid + 1, r);

    vector<int> candidates = {left.first, left.second, right.first, right.second};
    sort(candidates.rbegin(), candidates.rend());
    return {candidates[0], candidates[1]};
}

int main()
{
    vector<int> arr = {5, 1, 9, 7, 3, 8};
    pair<int, int> result = largestPair(arr, 0, arr.size() - 1);

    cout << "Largest pair: " << result.first << " and " << result.second << "\n";

    return 0;
}
