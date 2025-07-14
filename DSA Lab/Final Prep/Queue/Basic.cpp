#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) // constructor
    {
        this->data = val;
        this->next = NULL;
    }
};
class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }
    void push(int data) // insert data at tail // TM => O(1)
    {
        Node *newNode = new Node(data);
        if (empty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop() // TM => O(1)
    {
        if (empty())
        {
            cout << "Empty\n";
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    int front() // TM => O(1)
    {
        if (empty())
        {
            cout << "Empty\n";
            return -1;
        }
        return head->data;
    }
    bool empty()
    {
        return head == NULL;
    }
};
int main()
{
    Queue q;
    // queue<int> q; // using STL
    q.push(10);
    q.push(20);
    q.push(30);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}