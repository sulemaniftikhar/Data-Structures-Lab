#include <iostream>

using namespace std;

class IntStack
{
private:
    int top;
    int *stackArray;
    int stackSize;
    void initializeStack(size_t size);

public:
    IntStack(size_t size);
    void push(int data);
    int pop(int &value);
    bool isFull();
    bool isEmpty();
    int topElement();
};

int main()
{
    IntStack stack(10);
    cout << boolalpha;

    int popValue;
    cout << "Stack empty: " << stack.isEmpty() << endl;
    stack.pop(popValue);

    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);

    cout << "Stack empty: " << stack.isEmpty() << endl;

    cout << "Top element on the stack: " << stack.topElement() << endl;

    stack.pop(popValue);
    stack.pop(popValue);

    cout << "Stack full: " << stack.isFull() << endl;

    stack.push(25);
    stack.push(30);
    stack.push(35);
    stack.push(40);
    stack.push(45);
    stack.push(50);
    stack.push(55);
    stack.push(60);

    stack.push(65);
    cout << "Stack full: " << stack.isFull() << endl;

    stack.pop(popValue);

    stack.pop(popValue);

    cout << "Top element on the stack: " << stack.topElement() << endl;

    system("pause");
    return 0;
}

void IntStack::initializeStack(size_t size)
{
    stackArray = new int[size];
    top = -1;
    stackSize = size;
}

IntStack::IntStack(size_t size)
{
    if (size > 0)
    {
        initializeStack(size);
    }
    else
    {
        cout << "Size of stack cannot be -ve" << endl;
    }
}

bool IntStack::isFull()
{
    if (top == stackSize - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IntStack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void IntStack::push(int data)
{
    if (isFull())
    {
        cout << "Stack overflow -> Value " << data << " has NOT been pushed to stack" << endl;
    }
    else
    {
        top++;
        stackArray[top] = data;
        cout << "Value " << data << " has been pushed to stack" << endl;
    }
}

int IntStack::pop(int &value)
{
    if (isEmpty())
    {
        cout << "Stack underflow -> cannot pop from empty stack" << endl;
        value = INT_MIN;
        return value;
    }
    else
    {
        cout << "Value " << stackArray[top] << " has been popped" << endl;
        value = stackArray[top];
        top--;
        return value;
    }
}

int IntStack::topElement()
{
    if (!isEmpty())
    {
        return stackArray[top];
    }
    else
    {
        cout << "Stack underflow (Empty)" << endl;
        return INT_MIN;
    }
}