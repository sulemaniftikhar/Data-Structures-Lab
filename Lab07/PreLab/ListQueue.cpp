#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue
{
private:
    Node *front;
    Node *rear;

    void makeNull()
    {
        int val;
        while (!isEmpty())
        {
            deQueue(val);
            cout << "DeQueue: " << val << endl;
        }
    }

public:
    Queue()
        : front(nullptr), rear(nullptr) {}

    ~Queue()
    {
        makeNull();
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enQueue(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    bool deQueue(int &val)
    {
        if (isEmpty())
        {
            cout << "Underflow" << endl;
            return false;
        }
        if (rear == front)
        {
            val = front->data;
            delete front;
            rear = front = nullptr;
            return true;
        }
        val = front->data;
        Node *temp = front->next;
        delete front;
        front = temp;
        return true;
    }

    bool getFront(int &val)
    {
        if (!isEmpty())
        {
            val = front->data;
            return true;
        }
        else
        {
            cout << "No front of an empty Queue" << endl;
            return false;
        }
    }
};

int main()
{
    Queue myQ;
    int frontVal;
    int deqVal;

    myQ.enQueue(1);
    myQ.enQueue(2);
    myQ.enQueue(3);
    myQ.enQueue(4);
    myQ.enQueue(5);
    myQ.enQueue(6);

    if (myQ.getFront(frontVal))
    {
        cout << "Front Value: " << frontVal << endl;
    }

    if (myQ.deQueue(deqVal))
    {
        cout << "Dequeue: " << deqVal << endl;
    }
    if (myQ.deQueue(deqVal))
    {
        cout << "Dequeue: " << deqVal << endl;
    }
    if (myQ.deQueue(deqVal))
    {
        cout << "Dequeue: " << deqVal << endl;
    }

    if (myQ.getFront(frontVal))
    {
        cout << "Front Value: " << frontVal << endl;
    }

    return 0;
}