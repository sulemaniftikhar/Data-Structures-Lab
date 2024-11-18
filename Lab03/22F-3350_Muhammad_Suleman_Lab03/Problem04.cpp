#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char data) : data(data), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    void insertAtBeginning(char data)
    {
        Node *current = new Node(data);
        current->next = head;
        head = current;
    }

    void insertAtEnd(char data)
    {
        Node *newNode = new Node(data);
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

    void insertAtPosition(char data, int position)
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

    LinkedList reverseCopy()
    {
        LinkedList reversedList;
        Node *current = head;
        while (current != nullptr)
        {
            reversedList.insertAtBeginning(current->data);
            current = current->next;
        }
        return reversedList;
    }
};

int main()
{
    LinkedList list;
    list.insertAtBeginning('A');
    list.insertAtBeginning('B');
    list.insertAtBeginning('C');
    list.insertAtBeginning('D');
    list.insertAtBeginning('E');
    list.insertAtBeginning('F');
    list.insertAtBeginning('G');
    list.insertAtBeginning('H');
    list.insertAtBeginning('I');
    list.insertAtBeginning('J');

    LinkedList reversedList = list.reverseCopy();

    cout << "Original list: ";
    list.printList();

    cout << "Reversed list: ";
    reversedList.printList();

    return 0;
}