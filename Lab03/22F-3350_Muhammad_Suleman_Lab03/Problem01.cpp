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
        if (head == nullptr)
        {
            head = current;
            return;
        }
        else
        {
            current->next = head;
            head = current;
        }
    }

    void insertAtEnd(int data)
    {
        // if list was empty
        if (head == nullptr)
        {
            insertAtBeginning(data);
            return;
        }
        else
        {
            Node *newNode = new Node(data);
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
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
        else
        {
            Node *current = head;
            while (current != nullptr)
            {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "nullptr" << endl;
        }
    }

    void reverseList()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        Node *prev = nullptr;
        Node *curr = head;
        Node *temp = nullptr;

        while (curr != nullptr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
    }

    void middleOfList()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *noob = head;
            Node *pro = head;
            while (pro != nullptr && pro->next != nullptr)
            {
                noob = noob->next;
                pro = pro->next->next;
            }
            cout << "The middle of list is " << noob->data << endl;
        }
    }

    void traveseReverse(Node *head)
    {
        if (head == nullptr)
        {
            return;
        }
        traveseReverse(head->next);
        cout << head->data << " -> ";
    }

    void guess(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        cout << head->data << " -> ";

        if (head->next != NULL)
        {
            guess(head->next->next);
        }
        cout << head->data << " -> ";
    }

    Node *reverseK(Node *head, int k)
    {
        // base case
        if (!head)
            return NULL;

        Node *current = head;
        Node *prev = NULL;
        Node *temp = NULL;
        int count = 0;

        /*reverse first k nodes of the linked list */
        while (current != NULL && count < k)
        {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
            count++;
        }

        /* next is now a pointer to (k+1)th node
        Recursively call for the list starting from current.
        And make rest of the list as next of first node */
        if (temp != NULL)
            head->next = reverseK(temp, k);

        /* prev is new head of the input list */
        return prev;
    }

    void reverse(Node **h)
    {
        if (*h == nullptr || (*h)->next == nullptr)
        {
            return;
        }
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        *h = prev;
    }
};

int main()
{
    LinkedList list;
    list.insertAtBeginning(6);
    list.insertAtBeginning(5);
    list.insertAtBeginning(4);
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtPosition(1, 1);
    list.insertAtEnd(7);
    list.printList();

    // list.reverseList();
    // list.printList();

    // list.middleOfList();

    // list.reverse(&list.head);
    // cout << "Head: " << list.head->data << endl;
    // list.printList();

    // Node *temp = list.head;
    // list.traveseReverse(temp);

    list.guess(list.head);

    return 0;
}