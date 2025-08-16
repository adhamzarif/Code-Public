#include <bits/stdc++.h>
using namespace std;

int countEven(int arr[], int left, int right)
{
    if (left == right)
    {
        if (arr[left] % 2 == 0)
            return 1;
        else
            return 0;
    }

    int mid = (left + right) / 2;

    int leftCount = countEven(arr, left, mid);
    int rightCount = countEven(arr, mid + 1, right);

    return leftCount + rightCount;
}

int main()
{
    int arr[] = {3, 4, 7, 8, 10, 13, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    int totalEven = countEven(arr, 0, n - 1);

    cout << "Total even numbers in the array: " << totalEven << endl;

    return 0;
}
