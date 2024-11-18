#include <iostream>

using namespace std;

class CircularQueue
{
private:
    int *queueArray;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int size)
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
        else if (front == rear)
        {
            int value = queueArray[front];
            front = -1;
            rear = -1;
            return value;
        }
        else
        {
            int value = queueArray[front];
            front = (front + 1) % size;
            return value;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Nothing to display (Queue is empty)" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (i != rear)
        {
            cout << queueArray[i] << " ";
            i = (i + 1) % size;
        }
        cout << queueArray[rear] << endl;
    }

    void rearrange()
    {
        if (isEmpty())
        {
            cout << "Cannot rearrange elements (Queue is empty)" << endl;
            return;
        }

        int halfSize = size / 2;
        CircularQueue extraQueue(halfSize);
        for (int i = 0; i < halfSize; i++)
        {
            extraQueue.enQueue(deQueue());
        }
        while (!extraQueue.isEmpty())
        {
            enQueue(extraQueue.deQueue());
            enQueue(deQueue());
        }
    }
};

int main()
{
    CircularQueue queue(8);

    queue.enQueue(3);
    queue.enQueue(2);
    queue.enQueue(5);
    queue.enQueue(6);
    queue.enQueue(7);
    queue.enQueue(9);
    queue.enQueue(8);
    queue.enQueue(4);

    cout << "\n->Before arrangement<-\n"
         << endl;
    queue.display();

    cout << "\n->After arrangement<-\n"
         << endl;
    queue.rearrange();

    queue.display();

    return 0;
}