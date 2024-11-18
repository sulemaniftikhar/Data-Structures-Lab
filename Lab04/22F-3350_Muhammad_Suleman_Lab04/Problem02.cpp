
#include <iostream>

using namespace std;

class Node
{
private:
public:
    int data;
    Node *next;
    Node *prev;

    Node()
        : data(0), next(nullptr), prev(nullptr) {}

    Node(int data)
        : data(data), next(nullptr), prev(nullptr) {}
};

class LinkedList
{
private:
    Node *Head;
    Node *Tail;

public:
    LinkedList()
        : Head(nullptr), Tail(nullptr) {}

    int getHead() { return Head->data; }
    int getTail() { return Tail->data; }

    // methods
    void insertAtBegin(int data);
    void insertAtEnd(int data);
    void inerstAfter(int data, int position);
    bool isEmpty();
    void deleteAtBegin();
    void deleteAtEnd();
    void deleteBefore(int position);
    void printList();
    void sortList();
};

int main()
{
    LinkedList list;

    list.insertAtBegin(10);
    list.insertAtBegin(20);
    list.insertAtBegin(30);
    list.insertAtBegin(40);
    list.insertAtBegin(50);
    list.insertAtEnd(100);

    cout << "Original List: ";
    list.printList();

    list.sortList();

    cout << "Sorted List: ";
    list.printList();

    return 0;
}
void LinkedList::insertAtBegin(int data)
{
    if (Head == nullptr)
    {
        Node *newNode = new Node(data);
        Head = newNode;
        Tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = Head;
        Head->prev = newNode;
        Head = newNode;
    }
}

void LinkedList::insertAtEnd(int data)
{
    Node *newNode = new Node(data);
    if (Head == nullptr)
    {
        Head = newNode;
        Tail = newNode;
    }
    else
    {
        newNode->prev = Tail;
        Tail->next = newNode;
        Tail = newNode;
    }
}

void LinkedList::inerstAfter(int data, int position)
{
    if (position <= 0)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node *curr = Head;
    int count = 0;
    while (curr != nullptr && count < position)
    {
        curr = curr->next;
        count++;
    }
    if (curr == nullptr)
    {
        cout << "Invalid position" << endl;
        return;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next = newNode;
        if (newNode->next == nullptr)
        {
            Tail = newNode;
        }
    }
}
void LinkedList::printList()
{
    if (Head == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }

    Node *curr = Head;
    while (curr != nullptr)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}
bool LinkedList::isEmpty()
{
    if (Head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void LinkedList::deleteAtBegin()
{
    //  empty list case
    if (Head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    // single node case
    if (Head->next == nullptr)
    {
        delete Head;
        Head = nullptr;
        Tail = nullptr;
    }
    else
    {
        // multiple node case
        Node *temp = Head->next;
        Head->next = nullptr;
        Head = temp;
    }
}
void LinkedList::deleteAtEnd()
{
    //  empty list case
    if (Head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    // single node case
    if (Head->next == nullptr)
    {
        delete Head;
        Head = nullptr;
        Tail = nullptr;
    }
    else
    {
        // multiple node case
        Node *temp = Tail->prev;
        Tail->prev = nullptr;
        delete Tail;
        Tail = temp;
        Tail->next = nullptr;
    }
}
void LinkedList::deleteBefore(int position)
{
    if (position <= 1)
    {
        cout << "Invalid position" << endl;
        return;
    }
    //  empty list case
    if (Head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *prev = nullptr;
    Node *curr = Head;
    int count = 0;
    while (curr != nullptr && count < position - 1)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    // if head to delete
    if (prev == Head)
    {
        deleteAtBegin();
        return;
    }
    // if tail to delete
    if (curr)
    {
        if (curr->next == nullptr)
        {
            deleteAtEnd();
            return;
        }
        else
        {
            // in between head and tail
            prev->prev->next = prev->next;
            curr->prev = prev->prev;
            prev->prev = nullptr;
            prev->next = nullptr;
            delete prev;
        }
    }
    else
    {
        cout << "Invalid position" << endl;
    }
}
void LinkedList::sortList()
{
    if (Head == nullptr || Head->next == nullptr)
    {
        return;
    }

    bool swapped;
    Node *curr;
    do
    {
        swapped = false;
        curr = Head;
        while (curr->next != nullptr)
        {
            if (curr->data > curr->next->data)
            {
                // swap links of adjacent nodes
                if (curr->prev != nullptr)
                {
                    curr->prev->next = curr->next;
                }
                else
                {
                    // if the current node is the head node
                    Head = curr->next;
                }
                curr->next->prev = curr->prev;
                curr->prev = curr->next;
                curr->next = curr->next->next;
                curr->prev->next = curr;
                if (curr->next != nullptr)
                {
                    curr->next->prev = curr;
                }
                if (curr->next == nullptr)
                {
                    // if the current node is the tail node
                    Tail = curr;
                }
                swapped = true;
            }
            else
            {
                curr = curr->next;
            }
        }
    } while (swapped);
}