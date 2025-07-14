#include <bits/stdc++.h>
using namespace std;
class Stack
{
    list<int> ll;

public:
    void push(int val) // O(1) ~TC
    {
        ll.push_front(val);
    }
    void pop() // O(1) ~TC
    {
        ll.pop_front();
    }
    int top() // O(1) ~TC
    {
        return ll.front();
    }
    bool empty()
    {
        return ll.size() == 0; // size 0 true else false
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