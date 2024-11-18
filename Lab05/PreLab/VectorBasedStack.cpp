#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<int> vect;

public:
    Stack() {}
    bool isEmpty();
    int GetTop();
    void push(int data);
    bool pop();
    int sizeOfStack();
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout << "Size: " << st.sizeOfStack() << endl;

    cout << st.GetTop() << endl;

    st.pop();
    st.pop();
    cout << "Size: " << st.sizeOfStack() << endl;
    cout << st.GetTop() << endl;

    return 0;
}

bool Stack::isEmpty()
{
    if (vect.empty())
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
        return vect.back();
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
    vect.push_back(data);
    cout << "Value " << data << " has been pushed to stack" << endl;
}

bool Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow" << endl;
        return false;
    }
    else
    {
        cout << "Value " << vect.back() << " has been popped" << endl;
        vect.pop_back();
        return true;
    }
}

int Stack::sizeOfStack()
{
    return vect.size();
}