#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node Node;


Node* head = NULL;
Node* tail = NULL;

Node* createNode(int data)
{
    Node* temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void add_last(int data)
{
    if(head==NULL)
    {
        head = createNode(data);
        tail = head;
    }
    else
    {
        Node* temp = createNode(data);
        tail->next = temp;
        tail = tail->next;
    }
}

void add_first(int data)
{
    if(head==NULL)
    {
        head = createNode(data);
        tail = head;
    }
    else
    {
        Node* temp = createNode(data);
        temp->next = head;
        head = temp;
    }
}


Node* linear_search(int key)
{
    for(Node* i = head; i!=NULL; i = i->next)
    {
        if(i->data == key)
        {
            return i;
        }
    }

    return NULL;
}

void add_after(int key, int data) /// key: after which element, data: what element
{
    Node* loc = linear_search(key);
    if(loc!=NULL)
    {
        Node* temp = createNode(data);
        temp->next = loc->next;
        loc->next = temp;
    }
}

void add_before(int key, int data)  /// key: after which element, data: what element
{
    if(head==NULL) return;
    else if(head->data==key) add_first(data);
    else
    {
        Node* second_leg = head;
        Node* first_leg = head->next;

        while(first_leg!=NULL)
        {
            if(first_leg->data==key)
                break;
            else
            {
                first_leg = first_leg->next;
                second_leg = second_leg->next;
            }
        }

        if(first_leg!=NULL) /// KEY FOUND
        {
            Node* temp = createNode(data);
            temp->next = first_leg;
            second_leg->next = temp;
        }
    }
}

void printList()
{
    printf("Linked List: ");
    for(Node* i = head; i!=NULL; i = i->next)
    {
        printf("%d ", i->data);
    }
    printf("\n");
}

void delete_first()
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_last()
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        if (head == tail)
        {
            free(head);
            head = NULL;
            tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        free(tail);
        tail = temp;
        tail->next = NULL;
    }
}

void delete_any(int data)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        if (head->data == data)
        {
            delete_first();
            return;
        }

        Node *prev = head;
        Node *curr = head->next;

        while (curr != NULL)
        {
            if (curr->data == data)
            {
                prev->next = curr->next;
                if (curr == tail)
                    tail = prev;
                free(curr);
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}

void find_mid_node() /// Time complexity must be O(n/2)
{
    if (head == NULL)
    {
        return;
    }
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int mid_index = count / 2;
    temp = head;

    for (int i = 0; i < mid_index; i++)
    {
        temp = temp->next;
    }
}

void reverse_list() /// Space Complexity must be O(1), Time Complexity can be O(n)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    tail = head;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void sort_list() /// bubble sort or selection sort
{
    if(head == NULL)
    {
        return ;
    }
    else
    {
        for (Node* i = head; i->next != NULL; i = i->next)
        {
            for (Node* j = i->next; j != NULL; j = j->next)
            {
                if(i -> data > j -> data)
                {
                    int temp = i -> data;
                    i -> data = j -> data;
                    j -> data = temp;
                }
            }
        }
    }
}

int main()
{
    add_last(10);
    add_last(20);
    add_last(30);
    add_last(40);

    printList();

    add_first(50);
    printList();

    add_after(30, 100);
    printList();


    add_before(20, 15);
    printList();

    return 0;
}
