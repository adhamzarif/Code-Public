#include <bits/stdc++.h>
using namespace std;

void Max_Crossing_sum(vector<int> &a, int low, int mid, int high,
                      int &max_sum, int &l_idx, int &r_idx)
{
    int sum = 0;
    int left_sum = INT_MIN, left_index = -1;
    for (int i = mid; i >= low; i--)
    {
        sum += a[i];
        if (sum >= left_sum)
        {
            left_sum = sum;
            left_index = i;
        }
    }

    int right_sum = INT_MIN, right_index = -1;
    sum = 0;
    for (int j = mid + 1; j <= high; j++)
    {
        sum += a[j];
        if (sum >= right_sum)
        {
            right_sum = sum;
            right_index = j;
        }
    }

    max_sum = left_sum + right_sum;
    l_idx = left_index;
    r_idx = right_index;
}

void Find_Maximum_Subarray(vector<int> &a, int low, int high,
                           int &best_sum, int &best_low, int &best_high)
{
    if (low == high)
    {
        best_sum = a[low];
        best_low = best_high = low;
        return;
    }

    int mid = (low + high) / 2;

    int left_sum, left_low, left_high;
    Find_Maximum_Subarray(a, low, mid, left_sum, left_low, left_high);

    int right_sum, right_low, right_high;
    Find_Maximum_Subarray(a, mid + 1, high, right_sum, right_low, right_high);

    int cross_sum, cross_low, cross_high;
    Max_Crossing_sum(a, low, mid, high, cross_sum, cross_low, cross_high);

    if (left_sum >= right_sum && left_sum >= cross_sum)
    {
        best_sum = left_sum;
        best_low = left_low;
        best_high = left_high;
    }
    else if (right_sum >= left_sum && right_sum >= cross_sum)
    {
        best_sum = right_sum;
        best_low = right_low;
        best_high = right_high;
    }
    else
    {
        best_sum = cross_sum;
        best_low = cross_low;
        best_high = cross_high;
    }
}

int main()
{
    vector<int> v = {-2, 4, -1, 3, 5, -7, 6};
    int n = v.size();

    int sum, low, high;
    Find_Maximum_Subarray(v, 0, n - 1, sum, low, high);

    cout << "maximum subarray sum: " << sum << endl;
    cout << "maximum subarray: ";
    for (int i = low; i <= high; i++)
    {
        cout << v[i];
        if (i < high)
        {
            cout << ", ";
        }
    }
    cout << endl;
}
