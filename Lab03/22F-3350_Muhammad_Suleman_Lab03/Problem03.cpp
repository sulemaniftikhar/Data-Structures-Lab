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

    void merge(LinkedList &list1, LinkedList &list2, LinkedList &result)
    {
        Node *current1 = list1.head;
        Node *current2 = list2.head;

        while (current1 != nullptr && current2 != nullptr)
        {
            if (current1->data < current2->data)
            {
                result.insertAtEnd(current1->data);
                current1 = current1->next;
            }
            else
            {
                result.insertAtEnd(current2->data);
                current2 = current2->next;
            }
        }
        while (current1 != nullptr)
        {
            result.insertAtEnd(current1->data);
            current1 = current1->next;
        }
        while (current2 != nullptr)
        {
            result.insertAtEnd(current2->data);
            current2 = current2->next;
        }
    }
};

int main()
{
    LinkedList list1;
    list1.insertAtBeginning(40);
    list1.insertAtBeginning(30);
    list1.insertAtBeginning(20);
    list1.insertAtBeginning(10);
    cout << "List 1: ";
    list1.printList();

    LinkedList list2;
    list2.insertAtBeginning(90);
    list2.insertAtBeginning(80);
    list2.insertAtBeginning(70);
    list2.insertAtBeginning(60);
    cout << "List 2: ";
    list2.printList();

    LinkedList resultant;
    resultant.merge(list1, list2, resultant);
    cout << "Resultant list: ";
    resultant.printList();

    return 0;
}