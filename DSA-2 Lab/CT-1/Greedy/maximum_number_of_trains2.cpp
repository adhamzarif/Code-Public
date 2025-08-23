#include <bits/stdc++.h>
using namespace std;
//10 minutes of safety break between the departure n arrival
struct Train
{
    int arrival, departure;
};

int main()
{

    vector<Train> trains = {
        {1000, 1030}, {840, 1030}, {850, 1040}, {1700, 2000}, {800, 835}, {1300, 1800}, {1500, 1650}, {1200, 1380}};

    sort(trains.begin(), trains.end(), [](Train &a, Train &b)
         { return a.departure < b.departure; });

    vector<Train> selected;
    int last_dep = -1;

    for (auto &t : trains)
    {
        if (t.arrival >= last_dep + 10)
        {
            selected.push_back(t);
            last_dep = t.departure;
        }
    }

    cout << "Maximum trains scheduled = " << selected.size() << "\n";
    cout << "Trains chosen:\n";
    for (auto &t : selected)
    {
        cout << "[" << t.arrival << ", " << t.departure << "]\n";
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
//         if (trains[mid].departure + 10 <= trains[i].arrival)
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
//         {1000, 1030}, {840, 1030}, {850, 1040}, {1700, 2000}, {800, 835}, {1300, 1800}, {1500, 1650}, {1200, 1380}};

//     sort(trains.begin(), trains.end(), [](Train &a, Train &b)
//          { return a.departure < b.departure; });

//     int n = trains.size();
//     vector<int> dp(n, 0), parent(n, -1);

//     dp[0] = 1;
//     for (int i = 1; i < n; i++)
//     {
//         int excl = dp[i - 1];
//         int incl = 1;
//         int j = latestNonConflict(trains, i);
//         if (j != -1)
//             incl += dp[j];

//         if (incl > excl)
//         {
//             dp[i] = incl;
//             parent[i] = j;
//         }
//         else
//         {
//             dp[i] = excl;
//             parent[i] = parent[i - 1];
//         }
//     }

//     cout << "Maximum trains scheduled = " << dp[n - 1] << "\n";

//     vector<Train> chosen;
//     int i = n - 1;
//     int curr = dp[n - 1];
//     while (i >= 0)
//     {
//         int j = latestNonConflict(trains, i);
//         int incl = 1 + (j != -1 ? dp[j] : 0);
//         int excl = (i > 0 ? dp[i - 1] : 0);

//         if (incl >= excl)
//         {
//             chosen.push_back(trains[i]);
//             i = j;
//         }
//         else
//         {
//             i--;
//         }
//     }
//     reverse(chosen.begin(), chosen.end());

//     cout << "Trains chosen:\n";
//     for (auto &t : chosen)
//     {
//         cout << "[" << t.arrival << ", " << t.departure << "]\n";
//     }

//     return 0;
// }
