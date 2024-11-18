#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
};

class Stack
{
private:
    Node *top;
    void freeStack();

public:
    Stack() : top(nullptr) {}
    ~Stack() { freeStack(); }
    bool isEmpty();
    void push(int data);
    int pop();
    int topElement();
};

bool Stack::isEmpty()
{
    return top == nullptr;
}

void Stack::push(int data)
{
    Node *newNode = new Node(data);
    newNode->next = top;
    top = newNode;
}

int Stack::pop()
{
    if (!isEmpty())
    {
        Node *temp = top;
        top = top->next;
        int poppedVal = temp->data;
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
        cout << "Stack is empty" << endl;
        return -1;
    }
}

void Stack::freeStack()
{
    while (!isEmpty())
    {
        pop();
    }
}

class Queue
{
private:
    Stack input;
    Stack output;

public:
    Queue() {}

    ~Queue() {}

    bool isEmpty()
    {
        return input.isEmpty() && output.isEmpty();
    }

    void enqueue(int data)
    {
        input.push(data);
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        if (output.isEmpty())
        {
            while (!input.isEmpty())
            {
                output.push(input.pop());
            }
        }
        return output.pop();
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        if (output.isEmpty())
        {
            while (!input.isEmpty())
            {
                output.push(input.pop());
            }
        }
        return output.topElement();
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.front() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    return 0;
}