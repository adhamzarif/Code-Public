#include <bits/stdc++.h>
using namespace std;

struct Train
{
    int id;
    int arrival;
    int departure;
};

int main()
{
    vector<Train> trains = {
        {1, 1000, 1030}, {2, 840, 1030}, {3, 850, 1040}, {4, 1700, 2000}, {5, 800, 835}, {6, 1300, 1800}, {7, 1500, 1650}, {8, 1200, 1380}};

    sort(trains.begin(), trains.end(), [](Train &a, Train &b)
         { return a.departure < b.departure; });

    vector<Train> selected;
    int last_departure = -1;
    int min_gap = 10;

    for (auto &train : trains)
    {
        if (train.arrival >= last_departure + min_gap)
        {
            selected.push_back(train);
            last_departure = train.departure;
        }
    }

    cout << "Selected trains:\n";
    for (auto &train : selected)
    {
        cout << "Train " << train.id << ": [" << train.arrival << "," << train.departure << "]\n";
    }
    cout << "Maximum number of trains: " << selected.size() << endl;

    return 0;
}
