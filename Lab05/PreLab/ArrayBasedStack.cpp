#include <iostream>

using namespace std;

class Stack
{
private:
    int top;
    int *arr;
    int size;

public:
    Stack(int size);
    bool isFull();
    bool isEmpty();
    int GetTop();
    void push(int data);
    bool pop(int &value);
};

int main()
{
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.push(200);

    int value;
    s.pop(value);
    s.pop(value);
    s.pop(value);
    s.pop(value);
    s.pop(value);

    s.pop(value);

    return 0;
}

Stack::Stack(int size)
{
    if (size > 0)
    {
        arr = new int[size];
        top = -1;
        this->size = size;
    }
    else
    {
        cout << "Size of stack cannot be -ve" << endl;
    }
}

bool Stack::isFull()
{
    if (top == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isEmpty()
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

int Stack::GetTop()
{
    if (!isEmpty())
    {
        return arr[top];
    }
    else
    {
        cout << "NO top" << endl;
        cout << "Stack is empty" << endl;
        return INT_MIN;
    }
}

void Stack::push(int data)
{
    if (isFull())
    {
        cout << "Stack overflow" << endl;
        cout << "Value " << data << " has NOT been pushed to stack" << endl;
    }
    else
    {
        top++;
        arr[top] = data;
        cout << "Value " << data << " has been pushed to stack" << endl;
    }
}

bool Stack::pop(int &value)
{
    if (isEmpty())
    {
        cout << "Stack underflow" << endl;
        value = INT_MIN;
        return false;
    }
    else
    {
        cout << "Value " << arr[top] << " has been popped" << endl;
        value = arr[top];
        top--;
        return true;
    }
}