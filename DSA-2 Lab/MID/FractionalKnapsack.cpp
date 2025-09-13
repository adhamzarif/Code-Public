#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item{
public:
    string name;
    double weight, value, per_unit_value;
    Item(string n, double w, double v): name(n), weight(w),
                                        value(v), per_unit_value(v/w){}
    void display(){
        cout<<"name:"<<name<<" w:"<<weight<<" v:"<<value
                                    <<" unit value:"<<per_unit_value<<endl;
    }

};

bool Compare(Item i1, Item i2){
    return i1.per_unit_value > i2.per_unit_value;
}

void FractionalKnapsack(vector<Item> itemList, int n, int W){
    //find the maximum the profit
    sort(itemList.begin(), itemList.end(), Compare );
    for(Item i: itemList) i.display();

    double profit = 0;
    int i = 0;
    cout << "\nSelected items:" << endl;
    while(W > 0 && i < n){
        if( itemList[i].weight <= W ){
            //we can take the entire item
            profit += itemList[i].value;
            W = W - itemList[i].weight;
            itemList[i].display();
        }else{
            //knapsack does not have enough capacity
            //we have to take fractional amount
            double taken_weight = W;
            double p = taken_weight * itemList[i].per_unit_value;
            profit += p;
            W = 0;
            string name = itemList[i].name;
            double unit_value = itemList[i].per_unit_value;
            cout<<"name:"<<name<<" w:"<<taken_weight<<" v:"<<p<<" unit value:"<<unit_value<<endl;
        }
        i++;
    }

    cout << "Maximum profit:" << profit << endl;
}

int main(){
    vector<Item> items = {Item("Rice", 5, 300), Item("Saffron", 2, 8000),
                        Item("Salt", 10 , 200), Item("Sugar", 4, 400)
    };
    int W = 24; // knapsack capacity
    int n = items.size(); // number of items
    FractionalKnapsack(items, n, W);
}
