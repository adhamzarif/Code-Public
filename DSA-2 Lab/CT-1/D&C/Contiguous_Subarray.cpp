#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(vector<int> &arr, int l, int m, int r)
{
    int leftSum = 0, sum = 0;
    for (int i = m; i >= l; i--)
    {
        if (arr[i] < 0)
        {
            break;
        }
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = 0;
    sum = 0;
    for (int i = m + 1; i <= r; i++)
    {
        if (arr[i] < 0)
        {
            break;
        }
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxNonNegativeSum(vector<int> &arr, int l, int r)
{
    if (l > r)
    {
        return 0;
    }

    if (l == r)
    {
        return max(0, arr[l]);
    }

    int m = (l + r) / 2;

    int leftMax = maxNonNegativeSum(arr, l, m);
    int rightMax = maxNonNegativeSum(arr, m + 1, r);
    int crossMax = maxCrossingSum(arr, l, m, r);

    return max({leftMax, rightMax, crossMax});
}

int main()
{
    vector<int> arr = {1, 2, -3, 4, 5, 6, -1, 2, 3};
    int result = maxNonNegativeSum(arr, 0, arr.size() - 1);
    cout << "Maximum sum of non-negative contiguous subarray = " << result << "\n";
    return 0;
}
