#include <iostream>

using namespace std;

class Node
{
public:
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
    void freeStack() { while (pop()); }

public:
    Stack()
        : top(nullptr) {}

    ~Stack() { freeStack(); }

    bool isEmpty();
    void push(int data);
    bool pop();
    int getTop();
};

int main()
{
    Stack *s = new Stack;
    s->push(10);
    s->push(20);
    s->push(30);
    s->push(40);
    s->push(50);

    cout << s->getTop() << endl;

    delete s;

    return 0;
}

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
    cout << "Pushed " << data << endl;
    top = newNode;
}

bool Stack::pop()
{
    if (!isEmpty())
    {
        Node *temp = top;
        top = top->next;
        temp->next = nullptr;
        cout << "Popped " << temp->data << endl;
        delete temp;
        return true;
    }
    else
    {
        cout << "Stack underflow (Empty)" << endl;
        return false;
    }
}

int Stack::getTop()
{
    if (!isEmpty())
    {
        return top->data;
    }
    else
    {
        return INT_MIN;
    }
}