#include <bits/stdc++.h>
using namespace std;

int countInRange(vector<int> &arr, int l, int r, int x)
{
    int count = 0;
    for (int i = l; i <= r; i++)
    {
        if (arr[i] == x)
            count++;
    }
    return count;
}

int majorityElementRec(vector<int> &arr, int l, int r)
{
    if (l == r)
    {
        return arr[l];
    }

    int mid = (l + r) / 2;
    int leftMajor = majorityElementRec(arr, l, mid);
    int rightMajor = majorityElementRec(arr, mid + 1, r);

    if (leftMajor == rightMajor)
    {
        return leftMajor;
    }

    int leftCount = countInRange(arr, l, r, leftMajor);
    int rightCount = countInRange(arr, l, r, rightMajor);

    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int majorityElement(vector<int> &arr)
{
    return majorityElementRec(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int result = majorityElement(arr);
    cout << "Majority element = " << result << "\n";
    return 0;
}
