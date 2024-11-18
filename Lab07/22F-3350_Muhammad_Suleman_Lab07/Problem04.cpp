#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node()
		: data(0), next(nullptr) {}

	Node(int data)
		: data(data), next(nullptr) {}
};

class QueueLL
{
private:
	Node* front;
	Node* rear;

public:
	QueueLL()
		: front(nullptr), rear(nullptr) {}

	bool isEmpty()
	{
		return (front == nullptr);
	}

	void enQueue(int value)
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
	}

	int deQueue()
	{
		if (isEmpty())
		{
			cout << "Cannot dequeue value (Queue is empty)" << endl;
			return -1;
		}
		Node* temp = front;
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
		Node* current = front;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	bool checkConsecutiveTriplesAfterK(int k)
	{
		if (isEmpty() || front->next == nullptr)
		{
			return false;
		}

		Node* prev = front;
		Node* curr = front->next;

		while (curr && curr->next)
		{
			int count = 2;
			bool check = false;
			while (count--)
			{
				if (curr->data - prev->data != 1)
				{
					return false;
				}
				check = true;
				prev = curr;
				curr = curr->next;
			}

			int k1 = k;
			while (k1-- && curr)
			{
				prev = curr;
				curr = curr->next;
			}
		}
		return true;
	}

};

int main() {
	QueueLL queue;

	queue.enQueue(1);
	queue.enQueue(2);
	queue.enQueue(3);
	queue.enQueue(5);
	queue.enQueue(7);
	queue.enQueue(11);
	queue.enQueue(12);
	queue.enQueue(13);

	queue.display();

	int k = 2;
	if (queue.checkConsecutiveTriplesAfterK(k))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}

	QueueLL queue2;

	queue2.enQueue(1);
	queue2.enQueue(2);
	queue2.enQueue(3);
	queue2.enQueue(4);
	queue2.enQueue(5);
	queue2.enQueue(12);
	queue2.enQueue(14);
	queue2.enQueue(15);

	queue2.display();

	if (queue2.checkConsecutiveTriplesAfterK(k))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	system("pause");
	return 0;
}