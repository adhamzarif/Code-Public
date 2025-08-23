#include <bits/stdc++.h>
using namespace std;

void mergeCount(vector<pair<int, int>> &arr, int l, int m, int r, vector<int> &counts)
{
    vector<pair<int, int>> temp(r - l + 1);
    int i = l, j = m + 1, k = 0;
    int rightCounter = 0;

    while (i <= m && j <= r)
    {
        if (arr[i].first > arr[j].first)
        {
            temp[k++] = arr[j++];
            rightCounter++;
        }
        else
        {
            counts[arr[i].second] += rightCounter;
            temp[k++] = arr[i++];
        }
    }

    while (i <= m)
    {
        counts[arr[i].second] += rightCounter;
        temp[k++] = arr[i++];
    }

    while (j <= r)
    {
        temp[k++] = arr[j++];
    }

    for (int t = 0; t < temp.size(); t++)
    {
        arr[l + t] = temp[t];
    }
}

void mergeSortCount(vector<pair<int, int>> &arr, int l, int r, vector<int> &counts)
{
    if (l >= r)
    {
        return;
    }
    int m = (l + r) / 2;
    mergeSortCount(arr, l, m, counts);
    mergeSortCount(arr, m + 1, r, counts);
    mergeCount(arr, l, m, r, counts);
}

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = {nums[i], i};
    }
    vector<int> counts(n, 0);
    mergeSortCount(arr, 0, n - 1, counts);
    return counts;
}

int main()
{
    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = countSmaller(nums);

    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i != result.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]\n";

    return 0;
}
