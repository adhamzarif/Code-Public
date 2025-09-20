#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> trains = {
        {8, 12}, {6, 9}, {11, 14}, {2, 7}, {1, 7}, {12, 20}, {7, 12}, {13, 19}};

    // Sort by departure time
    sort(trains.begin(), trains.end(), [](auto &a, auto &b)
         { return a.second < b.second; });

    int count = 0;
    int last_dep = -1; // last train departure

    cout << "Selected trains:\n";

    for (auto &train : trains)
    {
        if (train.first >= last_dep + 1)
        { // at least 1 unit gap
            cout << "[" << train.first << ", " << train.second << ")\n";
            last_dep = train.second;
            count++;
        }
    }

    cout << "Maximum number of trains that can use platform: " << count << endl;
}
