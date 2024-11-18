#include <iostream>

using namespace std;

class Deque
{
private:
    int *queueArray;
    int front;
    int rear;
    int size;

public:
    Deque();
    Deque(int size);
    ~Deque();

    bool isEmpty();
    bool isFull();
    int getFront();
    int getRear();
    void display();
    
    bool enqueueRear(int value);
    bool dequeueFront();

    bool enqueueFront(int value);
    bool dequeueRear();
};

int main()
{
    Deque deque(5);

    deque.enqueueRear(3);
    deque.enqueueRear(4);
    deque.enqueueRear(5);
    deque.enqueueFront(2);
    deque.enqueueFront(1);
    deque.enqueueFront(55);
    deque.display();

    deque.dequeueFront();
    deque.dequeueRear();
    deque.display();

    return 0;
}

Deque::Deque()
    : front(-1), rear(-1), size(10)
{
    queueArray = new int[size];
}

Deque::Deque(int size)
    : front(-1), rear(-1), size(size)
{
    queueArray = new int[size];
}

bool Deque::isEmpty()
{
    return front == -1;
}

bool Deque::isFull()
{
    return (rear + 1) % size == front;
}

Deque::~Deque()
{
    delete[] queueArray;
}

bool Deque::enqueueRear(int value)
{
    if (isFull())
    {
        cout << "Cannot enqueueRear \"" << value << "\", (Queue is full)" << endl;
        return false;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    queueArray[rear] = value;
    return true;
}

bool Deque::dequeueFront()
{
    if (isEmpty())
    {
        cout << "Cannot dequeueFront (Queue is emtpy)" << endl;
        return false;
    }
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
    return true;
}

int Deque::getFront()
{
    if (isEmpty())
    {
        cout << "No front (Queue is emtpy)" << endl;
        return -1;
    }
    return queueArray[front];
}

int Deque::getRear()
{
    if (isEmpty())
    {
        cout << "No rear (Queue is emtpy)" << endl;
        return -1;
    }
    return queueArray[rear];
}

void Deque::display()
{
    if (isEmpty())
    {
        cout << "Cannot display (Queue is empty)" << endl;
        return;
    }
    int temp = front;
    while (temp != rear)
    {
        cout << queueArray[temp] << " ";
        temp = (temp + 1) % size;
    }
    cout << queueArray[temp];
    cout << endl;
}

bool Deque::enqueueFront(int value)
{
    if (isFull())
    {
        cout << "Cannot enqueueFront \"" << value << "\", (Queue is full)" << endl;
        return false;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        front = (front - 1 + size) % size;
    }
    queueArray[front] = value;
    return true;
}

bool Deque::dequeueRear()
{
    if (isEmpty())
    {
        cout << "Cannot dequeueRear (Queue is emtpy)" << endl;
        return false;
    }
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear = (rear - 1 + size) % size;
    }
    return true;
}