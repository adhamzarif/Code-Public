#include <bits/stdc++.h>
using namespace std;

struct Item
{
    string name;
    double weight;     // kg
    double value;      // Taka
    double unit_value; // value per kg
};

int main()
{
    vector<Item> items = {
        {"Rice", 12, 840, 840.0 / 12},
        {"Salt", 10, 870, 870.0 / 10},
        {"Saffron", 8, 2000, 2000.0 / 8},
        {"Sugar", 5, 500, 500.0 / 5}};

    // Sort items by unit value descending
    sort(items.begin(), items.end(), [](Item &a, Item &b)
         { return a.unit_value > b.unit_value; });

    double knapsack_capacity = 9.0; // per thief
    int thief_number = 1;

    while (true)
    {
        double capacity = knapsack_capacity;
        double profit = 0;
        vector<pair<string, double>> taken; // item name and weight taken

        bool any_taken = false;
        for (auto &item : items)
        {
            if (item.weight <= 0)
                continue;
            any_taken = true;

            double take = min(capacity, item.weight);
            profit += take * item.unit_value;
            capacity -= take;
            item.weight -= take;
            taken.push_back({item.name, take});
            if (capacity <= 0)
            {
                break;
            }
        }

        if (!any_taken)
        {
            break;
        } // shop empty

        // Print thief info
        cout << "Thief " << thief_number << " takes:\n";
        for (auto &p : taken)
        {
            cout << "  " << p.first << " : " << p.second << " kg\n";
        }
        cout << "Profit: " << profit << " Taka\n\n";
        thief_number++;
    }

    cout << "Total thieves needed: " << thief_number - 1 << endl;
}
