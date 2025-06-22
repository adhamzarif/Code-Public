#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int val) //Constructor
    {
        data = val;
        next = NULL;
    }
};
class List
{
    Node* head;
    Node* tail;

    public:
    List()
    {
        head = tail = NULL;
    }
};
int main()
{
    cout << "Hello\n";
    return 0;
}