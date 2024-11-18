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

    ~Queue()
    {
        delete[] queueArray;
    }

    bool isFull()
    {
        return (rear == size - 1);
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
            rear++;
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
            front++;
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
        cout << "\n->Displaying queue elements<-\n"<< endl;
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queueArray[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue queue(5);

    queue.enQueue(10);
    queue.enQueue(20);
    queue.enQueue(30);
    queue.enQueue(40);
    queue.enQueue(50);

    queue.enQueue(60);
    cout << "Dequeued value: " << queue.deQueue() << endl;
    cout << "Dequeued value: " << queue.deQueue() << endl;
    cout << "Dequeued value: " << queue.deQueue() << endl;
    cout << "Dequeued value: " << queue.deQueue() << endl;
    cout << "Dequeued value: " << queue.deQueue() << endl;
    queue.enQueue(60);

    queue.display();

    queue.display();

    return 0;
}