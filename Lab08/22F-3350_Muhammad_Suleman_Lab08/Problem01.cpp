#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int value)
		: data(value), next(nullptr) {}
};

class Queue
{
private:
	Node* front;
	Node* rear;

public:
	Queue()
		: front(nullptr), rear(nullptr) {}

	~Queue()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}

	bool isEmpty()
	{
		return front == nullptr;
	}

	void enqueue(int value)
	{
		Node* newNode = new Node(value);

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
		cout << value << " enqueued" << endl;
	}

	int dequeue()
	{
		if (isEmpty())
		{
			cout << "Unable to dequeue (Queue is empty)" << endl;
			return INT_MIN;
		}

		Node* temp = front;
		front = front->next;

		if (front == nullptr)
		{
			rear = nullptr;
		}

		cout << temp->data << " dequeued" << endl;
		int value = temp->data;
		delete temp;
		return value;
	}

	int getFront()
	{
		if (isEmpty())
		{
			cout << "No front element (Queue is empty)" << endl;
			return -1;
		}

		return front->data;
	}

	int getRear()
	{
		if (isEmpty())
		{
			cout << "No rear element (Queue is empty)" << endl;
			return -1;
		}
		return rear->data;
	}

	void QueueProcessing(Queue &q1, Queue &q2, Queue &q3)
	{
		while (!q3.isEmpty() || !q2.isEmpty())
		{
			q1.dequeue();
			if (!q2.isEmpty())
				q1.enqueue(q2.dequeue());
			if (!q3.isEmpty())
				q2.enqueue(q3.dequeue());
		}

		while (!q1.isEmpty())
		{
			q1.dequeue();
		}
	}
};

int main()
{
	Queue queue1;
	Queue queue2;
	Queue queue3;

	for (int i = 0; i < 5; i++)
	{
		queue1.enqueue(i + 1);
	}

	for (int i = 5; i < 10; i++)
	{
		queue2.enqueue(i + 1);
	}

	for (int i = 10; i < 15; i++)
	{
		queue3.enqueue(i + 1);
	}

	Queue temp;
	temp.QueueProcessing(queue1, queue2, queue3);

	system("pause");
	return 0;
}