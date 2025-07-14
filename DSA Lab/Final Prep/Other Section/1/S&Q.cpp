#include <bits/stdc++.h>
using namespace std;

class Stack
{
    vector<char> v;  // Changed to store characters

public:
    void push(char val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    char top()
    {
        return v[v.size() - 1];
    }
    bool empty()
    {
        return v.size() == 0;
    }
};

int main()
{
    string input = "HELLO";
    Stack s;

    // Push all characters to stack
    for (char ch : input)
    {
        s.push(ch);
    }

    // Pop all characters to reverse the string
    string reversed = "";
    while (!s.empty())
    {
        reversed += s.top();
        s.pop();
    }

    cout << "Original String: " << input << endl;
    cout << "Reversed String: " << reversed << endl;

    return 0;
}
