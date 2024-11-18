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
        return (front == -1);
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
        cout << "Enqueue value: " << value << endl;
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
};

int main()
{
    CircularQueue queue(5);

    queue.enQueue(10);
    queue.enQueue(20);
    queue.enQueue(30);
    queue.enQueue(40);
    queue.enQueue(50);

    queue.display();

    cout << "Dequeued value: " << queue.deQueue() << endl;
    cout << "Dequeued value: " << queue.deQueue() << endl;
    queue.enQueue(60);
    queue.enQueue(70);

    queue.display();

    return 0;
}