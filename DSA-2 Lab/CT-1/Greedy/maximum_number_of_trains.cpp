#include <bits/stdc++.h>
using namespace std;
//1 unit time gap consecutive trains
struct Train
{
    int arrival, departure;
};

int main()
{
    vector<Train> trains = {
        {8, 12}, {6, 9}, {11, 14}, {2, 7}, {1, 7}, {12, 20}, {7, 12}, {13, 19}};

    sort(trains.begin(), trains.end(), [](Train &a, Train &b)
         { return a.departure < b.departure; });

    vector<Train> selected;
    int count = 0, last_dep = -1;

    for (auto &t : trains)
    {
        if (t.arrival >= last_dep + 1)
        {
            selected.push_back(t);
            count++;
            last_dep = t.departure;
        }
    }

    cout << "Maximum trains scheduled = " << count << "\n";
    cout << "Trains chosen:\n";
    for (auto &t : selected)
    {
        cout << "[" << t.arrival << ", " << t.departure << ")\n";
    }

    return 0;
}


//Knapsack
// #include <bits/stdc++.h>
// using namespace std;

// struct Train
// {
//     int arrival, departure;
// };

// int latestNonConflict(vector<Train> &trains, int i)
// {
//     int low = 0, high = i - 1, ans = -1;
//     while (low <= high)
//     {
//         int mid = (low + high) / 2;
//         if (trains[mid].departure + 1 <= trains[i].arrival)
//         {
//             ans = mid;
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }
//     return ans;
// }

// int main()
// {
//     vector<Train> trains = {
//         {8, 12}, {6, 9}, {11, 14}, {2, 7}, {1, 7}, {12, 20}, {7, 12}, {13, 19}};

//     sort(trains.begin(), trains.end(), [](Train &a, Train &b)
//          { return a.departure < b.departure; });

//     int n = trains.size();
//     vector<int> dp(n, 0);

//     dp[0] = 1;
//     for (int i = 1; i < n; i++)
//     {
//         int excl = dp[i - 1];

//         int incl = 1;
//         int j = latestNonConflict(trains, i);
//         if (j != -1)
//             incl += dp[j];

//         dp[i] = max(excl, incl);
//     }

//     cout << "Maximum trains scheduled = " << dp[n - 1] << "\n";

//     return 0;
// }
