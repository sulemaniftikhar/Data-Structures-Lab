#include <iostream>

using namespace std;

class Queue
{
private:
    int *queueArray;
    int queueSize;
    int front;
    int rear;

public:
    Queue() : queueSize(10), front(-1), rear(-1)
    {
        queueArray = new int[10];
    }

    Queue(int size) : queueSize(size), front(-1), rear(-1)
    {
        queueArray = new int[queueSize];
    }

    ~Queue()
    {
        delete[] queueArray;
    }

    void makeNull()
    {
        rear = front = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % queueSize == front;
    }

    bool getFront(int &value)
    {
        if (!isEmpty())
        {
            value = queueArray[front];
            return true;
        }
        else
        {
            return false;
        }
    }

    bool enqueue(int value)
    {
        if (isFull())
        {
            cout << "Overflow" << endl;
            return false;
        }
        else
        {
            if (isEmpty())
            {
                rear = front = 0;
            }
            else
            {
                rear = (rear + 1) % queueSize;
            }
            queueArray[rear] = value;
            return true;
        }
    }

    bool dequeue(int &num)
    {
        if (isEmpty())
        {
            cout << "Underflow" << endl;
            return false;
        }
        num = queueArray[front];
        if (front == rear)
        {
            makeNull();
        }
        else
        {
            front = (front + 1) % queueSize;
        }
        return true;
    }
};

int main()
{
    Queue myQueue(5);

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    myQueue.enqueue(6);

    int frontValue;
    if (myQueue.getFront(frontValue))
    {
        cout << "Front element: " << frontValue << endl;
    }

    int dequeuedValue;
    if (myQueue.dequeue(dequeuedValue))
    {
        cout << "Dequeued element: " << dequeuedValue << endl;
    }
    if (myQueue.dequeue(dequeuedValue))
    {
        cout << "Dequeued element: " << dequeuedValue << endl;
    }
    if (myQueue.dequeue(dequeuedValue))
    {
        cout << "Dequeued element: " << dequeuedValue << endl;
    }
    if (myQueue.dequeue(dequeuedValue))
    {
        cout << "Dequeued element: " << dequeuedValue << endl;
    }
    if (myQueue.dequeue(dequeuedValue))
    {
        cout << "Dequeued element: " << dequeuedValue << endl;
    }

    return 0;
}