#include <bits/stdc++.h>
using namespace std;

void radixSort(vector<int> &a, int base)
{
    int n = a.size();
    int maxVal = *max_element(a.begin(), a.end());

    for (int exp = 1; maxVal / exp > 0; exp *= base)
    {

        vector<queue<int>> buckets(base);

        for (int i = 0; i < n; i++)
        {
            int digit = (a[i] / exp) % base;
            buckets[digit].push(a[i]);
        }

        int idx = 0;
        for (int i = 0; i < base; i++)
        {
            while (!buckets[i].empty())
            {
                a[idx++] = buckets[i].front();
                buckets[i].pop();
            }
        }
    }
}

int main()
{
    int n, base;
    cin >> n >> base;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    radixSort(a, base);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}




//Task

// #include <bits/stdc++.h>
// using namespace std;

// void radixSort(vector<int>& a, int base) {
//     int maxValue = *max_element(a.begin(), a.end());

//     for (int exp = 1; maxValue / exp > 0; exp *= base) {
//         vector<vector<int>> buckets(base);

//         for (int x : a) {
//             int digit = (x / exp) % base;
//             buckets[digit].push_back(x);
//         }

//         int idx = 0;
//         for (int i = base-1; i >= 0; i--) {
//             for (int x : buckets[i]) {
//                 a[idx++] = x;
//             }
//         }
//     }
// }

// int main() {
//     int n, base;
//     cin >> n >> base;

//     vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     radixSort(a, base);
    
//     for (int i = 0; i < n; i++) {
//         cout << a[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }