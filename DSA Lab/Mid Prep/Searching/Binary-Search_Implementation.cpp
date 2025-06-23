#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int val;
    cin >> val;
    int flag = 0;
    // Implementing Binary Search
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        // finding mid
        int mid = (l + r) / 2;
        if (a[mid] == val)
        {
            flag = 1;
            break;
        }
        else if (a[mid] > val) // if value is smaller than mid, then we will go left to find
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (flag == 1)
    {
        cout << "found\n";
    }
    else
    {
        cout << "not found\n";
    }

    return 0;
}