//#include <iostream>
//
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node *next;
//
//	Node()
//		: data(0), next(0) {}
//
//	Node(int data)
//		: data(data), next(nullptr) {}
//};
//
//class StackLL
//{
//private:
//	Node *top;
//	void freeStack()
//	{
//		while (!isEmpty())
//		{
//			pop();
//		}
//		cout << "Stack empty: " << isEmpty() << endl;
//	}
//
//public:
//	StackLL()
//		: top(nullptr) {}
//
//	~StackLL() { freeStack(); }
//	bool isEmpty();
//	void push(int data);
//	int pop();
//	int topElement();
//};
//
//int main()
//{
//	StackLL *stack = new StackLL;
//	cout << boolalpha;
//
//	cout << "Stack empty: " << stack->isEmpty() << endl;
//
//	stack->push(10);
//	stack->push(20);
//	stack->push(30);
//	stack->push(40);
//	stack->push(50);
//
//	cout << "Stack empty: " << stack->isEmpty() << endl;
//	cout << "Top Element: " << stack->topElement() << endl;
//
//	delete stack;
//
//	system("pause");
//	return 0;
//}
//
//bool StackLL::isEmpty()
//{
//	if (top == nullptr)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//void StackLL::push(int data)
//{
//	Node *newNode = new Node(data);
//	newNode->next = top;
//	cout << "Pushed " << data << endl;
//	top = newNode;
//}
//
//int StackLL::pop()
//{
//	if (!isEmpty())
//	{
//		Node *temp = top;
//		top = top->next;
//		temp->next = nullptr;
//		int poppedVal = temp->data;
//		cout << "Popped " << temp->data << endl;
//		delete temp;
//		return poppedVal;
//	}
//	else
//	{
//		cout << "Stack underflow (Empty)" << endl;
//		return INT_MIN;
//	}
//}
//
//int StackLL::topElement()
//{
//	if (!isEmpty())
//	{
//		return top->data;
//	}
//	else
//	{
//		return INT_MIN;
//	}
//}