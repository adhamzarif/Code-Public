#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
// Insert at End
void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
// Delete by Value
void deleteByValue(Node *&head, int val)
{
    if (head == nullptr)
        return;

    if (head->data == val)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != val)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
        return;

    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
// Search for a Value
bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}
// Print List
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " → ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

int main()
{
    Node *head = nullptr;

    // Insert elements
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    // Print list after insertion
    cout << "Linked List after insertions: ";
    printList(head);

    // Delete a value
    deleteByValue(head, 20);

    // Print list after deletion
    cout << "Linked List after deleting 20: ";
    printList(head);

    // Search for 30
    if (search(head, 30))
    {
        cout << "Search 30: Found" << endl;
    }
    else
    {
        cout << "Search 30: Not Found" << endl;
    }

    // Search for 100
    if (search(head, 100))
    {
        cout << "Search 100: Found" << endl;
    }
    else
    {
        cout << "Search 100: Not Found" << endl;
    }

    return 0;
}
