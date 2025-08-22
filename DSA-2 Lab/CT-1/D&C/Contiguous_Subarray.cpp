#include <bits/stdc++.h>
using namespace std;

vector<int> maxNonNegativeSubarray(vector<int> &arr)
{
    long long maxSum = -1, currSum = 0;
    vector<int> result, temp;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= 0)
        {
            currSum += arr[i];
            temp.push_back(arr[i]);
        }
        else
        {
            if (currSum > maxSum)
            {
                maxSum = currSum;
                result = temp;
            }
            currSum = 0;
            temp.clear();
        }
    }

    if (currSum > maxSum)
    {
        result = temp;
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 5, -7, 2, 3};
    vector<int> ans = maxNonNegativeSubarray(arr);

    cout << "Maximum sum non-negative subarray: ";
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
