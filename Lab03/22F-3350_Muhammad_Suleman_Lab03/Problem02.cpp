#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int data)
    {
        Node *current = new Node(data);
        current->next = head;
        head = current;
    }

    void insertAtEnd(int data)
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

    bool isPalindrome()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }

        Node *slow = head;
        Node *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *secondHalf = reverseList(slow->next);

        Node *firstHalf = head;
        while (secondHalf != nullptr)
        {
            if (firstHalf->data != secondHalf->data)
            {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }

private:
    Node *reverseList(Node *start)
    {
        Node *prev = nullptr;
        Node *current = start;
        Node *Next = nullptr;

        while (current != nullptr)
        {
            Next = current->next;
            current->next = prev;
            prev = current;
            current = Next;
        }
        return prev;
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

    if (list.isPalindrome())
    {
        cout << "The linked list is a palindrome" << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome" << endl;
    }

    LinkedList list2;
    if (list2.isPalindrome())
    {
        cout << "The linked list 2 is a palindrome" << endl;
    }
    else
    {
        cout << "The linked list 2 is not a palindrome" << endl;
    }

    return 0;
}