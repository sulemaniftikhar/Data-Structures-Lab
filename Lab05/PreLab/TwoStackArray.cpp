#include <iostream>

using namespace std;

class TwoStack
{
private:
    int size;
    int *arr;
    int top1;
    int top2;

public:
    TwoStack(int size)
        : size(size), top1(-1), top2(size)
    {
        arr = new int[size];
    }

    void push1(int value)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = value;
            cout << value << " has been pushed to Stack1" << endl;
        }
        else
        {
            cout << "Cannot push, Stack1 overflow" << endl;
        }
    }
    void push2(int value)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = value;
            cout << value << " has been pushed to Stack2" << endl;
        }
        else
        {
            cout << "Cannot push, Stack2 overflow" << endl;
        }
    }

    void pop1()
    {
        if (top1 > -1)
        {
            cout << arr[top1] << " has been popped from Stack1" << endl;
            top1--;
        }
        else
        {
            cout << "Cannot pop empty Stack1" << endl;
        }
    }

    void pop2()
    {
        if (top2 < size)
        {
            cout << arr[top2] << " has been popped from Stack2" << endl;
            top2++;
        }
        else
        {
            cout << "Cannot pop empty Stack2" << endl;
        }
    }

    bool isEmpty()
    {
        if (top1 == -1 && top2 == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    TwoStack stck(10);

    stck.pop1();
    stck.pop2();

    stck.push1(10);
    stck.push1(20);
    stck.push1(30);
    stck.push1(40);
    stck.push1(50);
    stck.push1(60);

    stck.push2(70);
    stck.push2(80);
    stck.push2(90);
    stck.push2(100);
    stck.push2(110);

    stck.pop2();
    stck.pop2();
    stck.pop2();
    stck.pop1();
    stck.pop1();
    stck.pop1();

    return 0;
}