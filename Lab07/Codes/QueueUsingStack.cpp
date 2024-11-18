#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node()
        : data(0), next(0) {}

    Node(int data)
        : data(data), next(nullptr) {}
};

class Stack
{
private:
    Node *top;
    void freeStack()
    {
        while (!isEmpty())
        {
            pop();
        }
        // cout << "Stack empty: " << isEmpty() << endl;
    }

public:
    Stack()
        : top(nullptr) {}

    ~Stack() { freeStack(); }
    bool isEmpty();
    void push(int data);
    int pop();
    int topElement();
    void printStack();
};

bool Stack::isEmpty()
{
    if (top == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack::push(int data)
{
    Node *newNode = new Node(data);
    newNode->next = top;
    // cout << "Pushed " << data << endl;
    top = newNode;
}

int Stack::pop()
{
    if (!isEmpty())
    {
        Node *temp = top;
        top = top->next;
        temp->next = nullptr;
        int poppedVal = temp->data;
        // cout << "Popped " << temp->data << endl;
        delete temp;
        return poppedVal;
    }
    else
    {
        cout << "Stack underflow (Empty)" << endl;
        return -1;
    }
}

int Stack::topElement()
{
    if (!isEmpty())
    {
        return top->data;
    }
    else
    {
        return -1;
    }
}

void Stack::printStack()
{
    if (isEmpty())
    {
        return;
    }
    Node *temp = top;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Queue
{
private:
    Stack s1;
    Stack s2;

public:

    void enQueue(int data)
    {
        if (s1.isEmpty())
        {
            s1.push(data);
            return;
        }
        while (!s1.isEmpty())
        {
            s2.push(s1.pop());
        }
        s1.push(data);
        while (!s2.isEmpty())
        {
            s1.push(s2.pop());
        }
    }

    int deQueue()
    {
        if (s1.isEmpty())
        {
            cout << "Cannot dequeue (Queue is empty)" << endl;
            return -1;
        }
        return s1.pop();
    }

    int top()
    {
        if (s1.isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return s1.topElement();
    }

    bool isEmpty()
    {
        return s1.isEmpty();
    }

    void display()
    {
        if (s1.isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            cout << "Displaying Queue: ";
            s1.printStack();
        }
    }
};

int main()
{
    Queue queue;
    cout << boolalpha;

    cout << queue.isEmpty() << endl;

    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    queue.enQueue(5);
    queue.enQueue(6);

    cout << queue.isEmpty() << endl;
    cout << queue.top() << endl;
    cout << queue.deQueue() << endl;

    queue.display();

    return 0;
}