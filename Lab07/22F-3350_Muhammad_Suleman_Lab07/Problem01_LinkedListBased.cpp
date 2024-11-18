#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
        : data(0), next(nullptr) {}

    Node(int data)
        : data(data), next(nullptr) {}
};

class QueueLL
{
private:
    Node *front;
    Node *rear;

public:
    QueueLL()
        : front(nullptr), rear(nullptr) {}

    ~QueueLL()
    {
        while (!isEmpty())
        {
            deQueue();
        }
    }

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enQueue(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int deQueue()
    {
        if (isEmpty())
        {
            cout << "Cannot dequeue value (Queue is empty)" << endl;
            return -1;
        }
        Node *temp = front;
        int value = temp->data;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Nothing to display (Queue is empty)" << endl;
            return;
        }
        cout << "\n->Displaying queue elements<-" << endl;
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    QueueLL queue;

    queue.enQueue(10);
    queue.enQueue(20);
    queue.enQueue(30);
    queue.enQueue(40);
    queue.enQueue(50);
    queue.enQueue(60);

    queue.display();

    cout << "\nDequeued value: " << queue.deQueue() << endl;
    cout << "Dequeued value: " << queue.deQueue() << endl;

    queue.display();

    return 0;
}