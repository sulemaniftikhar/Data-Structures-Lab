#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
public:
    int data;
    Node *next;

    Node()
        : data(0), next(nullptr) {}

    Node(int data)
        : data(data), next(nullptr) {}
};

class CircularLinkedList
{
    Node *Head;

public:
    CircularLinkedList()
        : Head(nullptr) {}

    int getHead() { return Head->data; }

    void insertAtBegin(int data);
    void deleteAtEnd();
    void printList();
    void menu()
    {
        cout << "CircularLinkedList" << endl;
        cout << "1) Insert at beginnig" << endl;
        cout << "2) Delete at end" << endl;
        cout << "Any other key to exit" << endl;
    }
};

int main()
{
    CircularLinkedList list;
    string choice;

    do
    {
        cout << "Menu:" << endl;
        cout << "1) Insert at the beginning" << endl;
        cout << "2) Delete at the end" << endl;
        cout << "3) Exit" << endl;
        cout << "Enter choice: ";
        getline(cin, choice);

        if (choice == "1")
        {
            int data;
            cout << "Enter data: ";
            cin >> data;
            cin.ignore();
            list.insertAtBegin(data);
            list.printList();
        }
        else if (choice == "2")
        {
            list.deleteAtEnd();
            list.printList();
        }
        else if (choice != "3")
        {
            cout << "Invalid choice" << endl;
            cout << "Please enter a valid option" << endl;
        }

    } while (choice != "3");

    cout << "Exiting program" << endl;
    return 0;
}
void CircularLinkedList::insertAtBegin(int data)
{
    if (Head == nullptr)
    {
        Node *newNode = new Node(data);
        newNode->next = newNode;
        Head = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        Node *temp = Head;
        while (temp->next != Head)
        {
            temp = temp->next;
        }
        newNode->next = Head;
        temp->next = newNode;
        Head = newNode;
    }
}
void CircularLinkedList::deleteAtEnd()
{
    if (Head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (Head->next == Head)
    {
        Head->next = nullptr;
        delete Head;
        Head = nullptr;
    }
    else
    {
        Node *prev = nullptr;
        Node *curr = Head;
        while (curr->next != Head)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
    }
}
void CircularLinkedList::printList()
{
    if (Head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        Node *temp = Head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != Head);
        cout << "Head" << endl;
    }
}