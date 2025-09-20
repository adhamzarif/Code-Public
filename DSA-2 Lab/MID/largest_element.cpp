#include <bits/stdc++.h>
using namespace std;

// Recursive function to find the largest element in array
int largest(int arr[], int n)
{
    if (n == 0)
    {
        return arr[0];
    } // base case
    return max(arr[n], largest(arr, n - 1));
}

int main()
{
    int a[] = {414, 52, 61, 7, 181};
    int n = sizeof(a) / sizeof(a[0]);
    int l = largest(a, n - 1); // pass last index
    cout << "largest: " << l << endl;
    return 0;
}
