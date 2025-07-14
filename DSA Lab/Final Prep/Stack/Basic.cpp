#include <bits/stdc++.h>
using namespace std;
class Stack
{
    vector<int> v;

public:
    void push(int val) // O(1) ~TC
    {
        v.push_back(val);
    }
    void pop() // O(1) ~TC
    {
        v.pop_back();
    }
    int top() // O(1) ~TC
    {
        return v[v.size() - 1];
    }
    bool empty()
    {
        return v.size() == 0; // size 0 true else false
    }
};
int main()
{
    Stack s;
    // stack<int> s; // using STL
    s.push(10);
    s.push(20);
    s.push(30);
    while (s.empty() == NULL)
    {
        cout << s.top() << " ";
        s.pop(); // without this it goes as infinite loop
    }
    cout << endl;

    return 0;
}