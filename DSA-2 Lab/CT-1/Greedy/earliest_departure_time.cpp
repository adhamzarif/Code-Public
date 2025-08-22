#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> trains = {
        {8, 12}, {6, 9}, {11, 14}, {2, 7}, {1, 7}, {12, 20}, {7, 12}, {13, 19}};

    sort(trains.begin(), trains.end(), [](auto &a, auto &b)
         { return a.second < b.second; });

    int last_departure = -1;
    int count = 0;

    for (auto &train : trains)
    {
        if (train.first >= last_departure + 1)
        {
            count++;
            last_departure = train.second;
        }
    }

    cout << "Maximum trains: " << count << endl;

    return 0;
}
