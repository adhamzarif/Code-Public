#include <bits/stdc++.h>
using namespace std;

int countEven(vector<int> &arr, int l, int r)
{
    if (l == r)
    {
        return (arr[l] % 2 == 0) ? 1 : 0;
    }

    int mid = (l + r) / 2;

    int leftCount = countEven(arr, l, mid);
    int rightCount = countEven(arr, mid + 1, r);

    return leftCount + rightCount;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 8};
    int n = arr.size();

    int result = countEven(arr, 0, n - 1);

    cout << "Total even numbers = " << result << "\n";

    return 0;
}
