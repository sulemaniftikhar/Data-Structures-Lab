#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
        : data(data), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
        : head(nullptr) {}

    void insertAtBeginning(int data)
    {

        Node *current = new Node(data);
        current->next = head;
        head = current;
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        // if list was empty
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAtPosition(int data, int position)
    {
        if (position <= 0)
        {
            cout << "Invalid position: " << position << endl;
            return;
        }

        if (position == 1)
        {
            insertAtBeginning(data);
            return;
        }

        Node *newNode = new Node(data);
        Node *current = head;
        int count = 1;
        while (current != nullptr && count < position - 1)
        {
            current = current->next;
            count++;
        }
        if (current == nullptr)
        {
            cout << "Invalid position: " << position << endl;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void printList()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void search(int data)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *current = head;
        int position = 1;
        while (current->data != data && current->next != nullptr)
        {
            current = current->next;
            position++;
        }
        if (current != nullptr)
        {
            cout << current->data << " is at " << position << endl;
        }
        else
        {
            cout << data << " not present in list" << endl;
        }
    }

    void swapFirstAndLast()
    {
        if (head == nullptr || head->next == nullptr)
        {
            cout << "List has less than two nodes" << endl;
            return;
        }

        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        swap(head->data, current->data);
    }
};

int main()
{
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(15);
    list.insertAtBeginning(20);
    list.insertAtEnd(25);
    list.insertAtEnd(30);
    list.insertAtPosition(5, 1);
    list.printList();
    list.search(15);

    list.swapFirstAndLast();
    list.printList();

    return 0;
}