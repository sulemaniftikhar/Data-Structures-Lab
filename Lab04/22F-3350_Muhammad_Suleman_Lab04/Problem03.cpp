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

    // copy constructor to store list in reverse order
    LinkedList(const LinkedList &list)
    {
        Node *current = list.Tail;
        while (current != nullptr)
        {
            this->insertAtEnd(current->data);
            current = current->prev;
        }
    }

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
};

int main()
{
    LinkedList list1;

    list1.insertAtBegin(10);
    list1.insertAtBegin(20);
    list1.insertAtBegin(30);
    list1.insertAtBegin(40);
    list1.insertAtBegin(50);
    list1.insertAtBegin(60);
    list1.insertAtBegin(70);
    list1.insertAtBegin(80);
    list1.insertAtBegin(90);
    list1.insertAtBegin(100);

    cout << "List 1" << endl;
    cout << "Head: " << list1.getHead() << "\nTail: " << list1.getTail() << endl;
    list1.printList();

    LinkedList list2(list1);
    cout << "List 2" << endl;
    cout << "Head: " << list2.getHead() << "\nTail: " << list2.getTail() << endl;
    list2.printList();

    system("pause");
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