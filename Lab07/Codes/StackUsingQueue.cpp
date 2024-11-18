#include <iostream>

using namespace std;

class Queue
{
private:
    int *queueArray;
    int front;
    int rear;
    int size;

public:
    Queue(int size)
        : front(-1), rear(-1), size(size)
    {
        queueArray = new int[size];
    }

    bool isFull()
    {
        return ((rear + 1) % size == front);
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    void enQueue(int value)
    {
        if (isFull())
        {
            cout << "Cannot enqueue value (Queue is full)" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        // cout << "Enqueue value: " << value << endl;
        queueArray[rear] = value;
    }

    int deQueue()
    {
        if (isEmpty())
        {
            cout << "Cannot dequeue value (Queue is empty)" << endl;
            return -1;
        }
        int value = queueArray[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
            return value;
        }
        else
        {
            front = (front + 1) % size;
            return value;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            // cout << "Queue is empty, no front element to peek" << endl;
            return -1;
        }
        return queueArray[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Nothing to display (Queue is empty)" << endl;
            return;
        }
        cout << "\n->Displaying queue elements<-\n"
             << endl;
        cout << "Queue elements: ";
        int i = front;
        while (i != rear)
        {
            cout << queueArray[i] << " ";
            i = (i + 1) % size;
        }
        cout << queueArray[rear] << endl;
    }

    ~Queue()
    {
        delete[] queueArray;
    }
};

class Stack
{
private:
    Queue *q1;
    Queue *q2;

public:
    Stack(int size)
    {
        q1 = new Queue(size);
        q2 = new Queue(size);
    }

    ~Stack()
    {
        delete q1;
        delete q2;
    }

    void push(int data)
    {
        q2->enQueue(data);
        while (!q1->isEmpty())
        {
            q2->enQueue(q1->deQueue());
        }
        swap(q1, q2);
    }

    int pop()
    {
        if (!q1->isEmpty())
        {
            return q1->deQueue();
        }
        cout << "Stack is empty." << endl;
        return -1;
    }

    int top()
    {
        if (!q1->isEmpty())
        {
            return q1->peek();
        }
        cout << "Stack is empty." << endl;
        return -1;
    }

    bool isEmpty()
    {
        return q1->isEmpty();
    }
};

int main()
{
    Stack stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    cout << "Top element: " << stack.top() << endl;
    // stack.pop();

    return 0;
}