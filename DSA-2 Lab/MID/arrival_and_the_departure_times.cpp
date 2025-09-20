#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> trains = {
        {1000, 1030}, {840, 1030}, {850, 1040}, {1700, 2000}, {800, 835}, {1300, 1800}, {1500, 1650}, {1200, 1380}};

    // Sort by departure time
    sort(trains.begin(), trains.end(), [](auto &a, auto &b)
         { return a.second < b.second; });

    int last_departure = -10; // initial value, ensures first train can be selected
    int count = 0;

    cout << "Selected trains:\n";
    for (auto &train : trains)
    {
        if (train.first >= last_departure + 10)
        { // safety break
            cout << "[" << train.first << ", " << train.second << "]\n";
            last_departure = train.second;
            count++;
        }
    }

    cout << "Maximum number of trains: " << count << endl;
}
