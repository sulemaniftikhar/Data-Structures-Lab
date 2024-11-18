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
    void insertAfter(int data, int position);
    bool isEmpty();
    void deleteAtBegin();
    void deleteAtEnd();
    void deleteBefore(int position);
    void printList();
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
    list.insertAfter(60, 10);

    list.printList();
    cout << "Head: " << list.getHead() << "\nTail: " << list.getTail() << endl;

    list.deleteAtBegin();
    list.printList();
    cout << "Head: " << list.getHead() << "\nTail: " << list.getTail() << endl;

    list.deleteAtEnd();
    list.printList();

    list.deleteBefore(2);
    list.printList();
    cout << "Head: " << list.getHead() << "\nTail: " << list.getTail() << endl;

    list.deleteBefore(5);
    list.printList();
    cout << "Head: " << list.getHead() << "\nTail: " << list.getTail() << endl;

    list.deleteBefore(4);
    list.printList();
    cout << "Head: " << list.getHead() << "\nTail: " << list.getTail() << endl;

    /*int choice, key, data;
    do
    {
        cout << "\nMenu Driven Doubly Linked List Implementation" << endl;
        cout << "1) Insert at Beginning" << endl;
        cout << "2) Insert After a Node" << endl;
        cout << "3) Insert at End" << endl;
        cout << "4) Delete at Beginning" << endl;
        cout << "5) Delete Before a Node" << endl;
        cout << "6) Delete at End" << endl;
        cout << "7) Check if Empty" << endl;
        cout << "8) Display List" << endl;
        cout << "9) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert at beginning: ";
            cin >> data;
            list.insertAtBegin(data);
            break;
        case 2:
            cout << "Enter key value after which to insert: ";
            cin >> key;
            cout << "Enter data to insert: ";
            cin >> data;
            list.inerstAfter(key, data);
            break;
        case 3:
            cout << "Enter data to insert at end: ";
            cin >> data;
            list.insertAtEnd(data);
            break;
        case 4:
            if (list.isEmpty())
            {
                cout << "List is empty!" << endl;
            }
            else
            {
                list.deleteAtBegin();
            }
            break;
        case 5:
            if (list.isEmpty())
            {
                cout << "List is empty!" << endl;
            }
            else
            {
                cout << "Enter key value before which to delete: ";
                cin >> key;
                list.deleteBefore(key);
            }
            break;
        case 6:
            if (list.isEmpty())
            {
                cout << "List is empty" << endl;
            }
            else
            {
                list.deleteAtEnd();
            }
            break;
        case 7:
            if (list.isEmpty())
            {
                cout << "List is empty" << endl;
            }
            else
            {
                cout << "List is not empty" << endl;
            }
            break;
        case 8:
            if (list.isEmpty())
            {
                cout << "List is empty" << endl;
            }
            else
            {
                list.printList();
            }
            break;
        case 9:
            cout << "Program Ended" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 9);*/

    return 0;
}
void LinkedList::insertAtBegin(int data)
{
    Node *newNode = new Node(data);
    if (Head == nullptr)
    {
        Head = newNode;
        Tail = newNode;
    }
    else
    {
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

void LinkedList::insertAfter(int data, int position)
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

        // Update the previous pointer of the node following newNode
        if (newNode->next != nullptr)
        {
            newNode->next->prev = newNode;
        }

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

// update here!
/*
void LinkedList::insertAfter(int data, int position)
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

        // Update the previous pointer of the node following newNode
        if (newNode->next != nullptr)
        {
            newNode->next->prev = newNode;
        }

        curr->next = newNode;

        if (newNode->next == nullptr)
        {
            Tail = newNode;
        }
    }
}
*/