#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int candidate = 0, count = 0;

    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        if (num == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return candidate;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

    int result = majorityElement(arr);
    cout << "Majority element: " << result << endl;

    return 0;
}
