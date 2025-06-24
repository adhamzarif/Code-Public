#include <iostream>
using namespace std;

class DoublyLinkedList {
public:
    struct Node {
        int data;
        Node* prev; // Pointer to the previous node
        Node* next; // Pointer to the next node

        // Constructor for Node for easier initialization
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head; // Pointer to the head of the list
    Node* tail; // Pointer to the tail of the list

public: // Explicitly public for member functions.
    // Constructor for the DoublyLinkedList
    DoublyLinkedList() : head(nullptr), tail(nullptr) {
        cout << "Doubly Linked List created." << endl;
    }

    ~DoublyLinkedList() {
        clearList(); // Call a helper function to free all nodes
        cout << "Doubly Linked List destroyed and memory freed." << endl;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data); // Create a new node using Node constructor

        if (head == nullptr) { // If the list is empty
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head; // New node points to the current head
            head->prev = newNode; // Current head's prev points to new node
            head = newNode;       // Update head to the new node
        }
        cout << "Inserted " << data << " at the beginning." << endl;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data); // Create a new node

        if (tail == nullptr) { // If the list is empty
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail; // New node's prev points to current tail
            tail->next = newNode; // Current tail's next points to new node
            tail = newNode;       // Update tail to the new node
        }
        cout << "Inserted " << data << " at the end." << endl;
    }

    // Function to delete a node with a specific data value
    void deleteNode(int data) {
        if (head == nullptr) { // Check if the list is empty
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* current = head;
        // Traverse the list to find the node to be deleted
        while (current != nullptr && current->data != data) {
            current = current->next;
        }

        if (current == nullptr) { // Node not found
            cout << "Node with data " << data << " not found." << endl;
            return;
        }

        // Case 1: Node to be deleted is the head
        if (current == head) {
            head = current->next; // Move head to the next node
            if (head != nullptr) {
                head->prev = nullptr; // New head has no previous node
            } else { // List becomes empty after deleting the only node
                tail = nullptr;
            }
        }
        // Case 2: Node to be deleted is the tail (and not the head, handled above)
        else if (current == tail) {
            tail = current->prev; // Move tail to the previous node
            if (tail != nullptr) {
                tail->next = nullptr; // New tail has no next node
            } else { // This case should ideally not be reached if current == head is handled first
                head = nullptr;
            }
        }
        // Case 3: Node to be deleted is in the middle of the list
        else {
            current->prev->next = current->next; // Link previous node to next node
            current->next->prev = current->prev; // Link next node to previous node
        }

        cout << "Deleted " << data << " from the list." << endl;
        delete current; // Free the memory of the deleted node using 'delete'
    }

    // Function to display the list from head to tail (forward traversal)
    void displayForward() const { // const to indicate it doesn't modify the object
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        cout << "List (forward): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to display the list from tail to head (backward traversal)
    void displayBackward() const { // const to indicate it doesn't modify the object
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = tail;
        cout << "List (backward): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void clearList() {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next; // Save next node before deleting current
            delete current;           // Free current node's memory
            current = nextNode;       // Move to the next node
        }
        head = nullptr; // Reset head and tail pointers
        tail = nullptr;
    }
};

int main() {
    // Create an object of DoublyLinkedList
    DoublyLinkedList myDoublyList;

    // Perform operations on the list
    myDoublyList.insertAtEnd(10);
    myDoublyList.insertAtBeginning(5);
    myDoublyList.insertAtEnd(20);
    myDoublyList.insertAtBeginning(1);

    myDoublyList.displayForward();
    myDoublyList.displayBackward();

    myDoublyList.deleteNode(5);
    myDoublyList.displayForward();

    myDoublyList.deleteNode(10);
    myDoublyList.displayForward();

    myDoublyList.deleteNode(1);
    myDoublyList.displayForward();

    myDoublyList.deleteNode(20);
    myDoublyList.displayForward();

    myDoublyList.displayBackward();

    return 0;
}