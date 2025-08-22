#include <bits/stdc++.h>
using namespace std;

struct Item
{
    string name;
    int quantity;
    int price;
    double price_per_kg;
};

int main()
{
    vector<Item> items = {
        {"Rice", 12, 840, 0},
        {"Salt", 10, 870, 0},
        {"Saffron", 8, 2000, 0},
        {"Sugar", 5, 500, 0}};

    int knapsack_capacity = 9;
    for (auto &item : items)
    {
        item.price_per_kg = (double)item.price / item.quantity;
    }

    int thief_id = 1;
    while (true)
    {
        int capacity = knapsack_capacity;
        vector<pair<string, int>> taken;
        double profit = 0;

        sort(items.begin(), items.end(), [](const Item &a, const Item &b)
             { return a.price_per_kg > b.price_per_kg; });

        for (auto &item : items)
        {
            if (item.quantity == 0)
                continue;
            int take_qty = min(item.quantity, capacity);
            if (take_qty > 0)
            {
                taken.push_back({item.name, take_qty});
                profit += take_qty * item.price_per_kg;
                item.quantity -= take_qty;
                capacity -= take_qty;
            }
            if (capacity == 0)
            {
                break;
            }
        }

        if (taken.empty())
        {
            break;
        }

        cout << "Thief " << thief_id << " carries:\n";
        for (auto &p : taken)
        {
            cout << "  " << p.second << " kg " << p.first << "\n";
        }
        cout << "Profit: " << (int)profit << " Taka\n\n";
        thief_id++;
    }

    cout << "Total thieves needed: " << thief_id - 1 << endl;

    return 0;
}
