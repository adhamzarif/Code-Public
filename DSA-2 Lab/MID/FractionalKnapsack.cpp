#include <bits/stdc++.h>
using namespace std;

void FractionalKnapsack(vector<pair<string, pair<double, double>>> items, int W)
{
    // sort by unit value using lambda
    sort(items.begin(), items.end(), [](auto &a, auto &b)
         {
        double unitA = a.second.second / a.second.first; // value / weight
        double unitB = b.second.second / b.second.first;
        return unitA > unitB; });

    cout << "Sorted items (by unit value):" << endl;
    for (auto i : items)
    {
        double unit = i.second.second / i.second.first;
        cout << "name:" << i.first
             << " w:" << i.second.first
             << " v:" << i.second.second
             << " unit value:" << unit << endl;
    }

    double profit = 0;
    int i = 0;
    cout << "\nSelected items:" << endl;

    while (W > 0 && i < items.size())
    {
        double weight = items[i].second.first;
        double value = items[i].second.second;
        double unit = value / weight;

        if (weight <= W)
        {
            // take whole item
            profit += value;
            W -= weight;
            cout << "name:" << items[i].first
                 << " w:" << weight
                 << " v:" << value
                 << " unit value:" << unit << endl;
        }
        else
        {
            // take fractional part
            double taken_weight = W;
            double p = taken_weight * unit;
            profit += p;
            W = 0;
            cout << "name:" << items[i].first
                 << " w:" << taken_weight
                 << " v:" << p
                 << " unit value:" << unit << endl;
        }
        i++;
    }

    cout << "\nMaximum profit: " << profit << endl;
}

int main()
{
    vector<pair<string, pair<double, double>>> items = {
        {"Rice", {5, 300}},
        {"Saffron", {2, 8000}},
        {"Salt", {10, 200}},
        {"Sugar", {4, 400}}};

    int W = 24; // knapsack capacity
    FractionalKnapsack(items, W);
}
