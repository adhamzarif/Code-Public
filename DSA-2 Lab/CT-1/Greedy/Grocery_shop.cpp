#include <bits/stdc++.h>
using namespace std;

struct Item
{
    string name;
    double weight, value;
    double ratio;
};

int main()
{
    vector<Item> items = {
        {"Rice", 12, 840, 0},
        {"Salt", 10, 870, 0},
        {"Saffron", 8, 2000, 0},
        {"Sugar", 5, 500, 0}};

    for (auto &it : items)
    {
        it.ratio = it.value / it.weight;
    }

    sort(items.begin(), items.end(), [](Item &a, Item &b)
         { return a.ratio > b.ratio; });

    double capacity = 9;
    int thiefCount = 0;

    while (true)
    {
        double currCap = capacity;
        double profit = 0;
        vector<pair<string, double>> taken;

        for (auto &it : items)
        {
            if (currCap <= 0)
            {
                break;
            }
            if (it.weight <= 0)
            {
                continue;
            }

            double take = min(currCap, it.weight);
            currCap -= take;
            it.weight -= take;
            profit += take * it.ratio;
            taken.push_back({it.name, take});
        }

        if (taken.empty())
        {
            break;
        }

        thiefCount++;
        cout << "Thief " << thiefCount << " takes:\n";
        for (auto &tk : taken)
        {
            cout << "  " << tk.second << " kg of " << tk.first << "\n";
        }
        cout << "Profit = " << profit << " taka\n\n";
    }

    cout << "Total thieves needed = " << thiefCount << "\n";

    return 0;
}
