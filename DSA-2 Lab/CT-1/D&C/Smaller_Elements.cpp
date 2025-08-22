#include <bits/stdc++.h>
using namespace std;

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 0);

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[i])
                count++;
        }
        result[i] = count;
    }
    return result;
}

int main()
{
    vector<int> nums = {5, 2, 6, 1};
    vector<int> ans = countSmaller(nums);

    cout << "Output: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
