#include <bits/stdc++.h>
using namespace std;

pair<int, int> findLargestPair(int arr[], int left, int right)
{
    if (left == right)
    {
        return {arr[left], INT_MIN};
    }

    int mid = (left + right) / 2;
    pair<int, int> leftPair;
    leftPair = findLargestPair(arr, left, mid);

    pair<int, int> rightPair;
    rightPair = findLargestPair(arr, mid + 1, right);

    vector<int> candidates = {leftPair.first, leftPair.second, rightPair.first, rightPair.second};

    sort(candidates.begin(), candidates.end(), greater<int>());

    return {candidates[0], candidates[1]};
}

int main()
{
    int arr[] = {12, 5, 7, 25, 19, 30, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> result;
    result = findLargestPair(arr, 0, n - 1);

    cout << "Largest pair in the array: "
         << result.first << " and " << result.second << endl;

    return 0;
}
