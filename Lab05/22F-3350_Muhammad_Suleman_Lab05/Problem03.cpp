//#include <iostream>
//
//using namespace std;
//
//class IntStack
//{
//private:
//	int top;
//	int *stackArray;
//	int stackSize;
//	void initializeStack(size_t size);
//
//public:
//	IntStack(size_t size);
//	~IntStack();
//	void push(int data);
//	int pop(int &value);
//	bool isFull();
//	bool isEmpty();
//	int topElement();
//	void reverseStack();
//};
//
//int main()
//{
//	IntStack stack(10);
//
//	int popValue;
//	for (int i = 1; i <= 5; i++)
//	{
//		stack.push(i * 10);
//		cout << i * 10 << " pushed" << endl;
//	}
//	stack.reverseStack();
//
//	for (int i = 0; i < 5; i++)
//	{
//		cout << "Popped: " << stack.pop(popValue) << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}
//
//void IntStack::initializeStack(size_t size)
//{
//	stackArray = new int[size];
//	top = -1;
//	stackSize = size;
//}
//
//IntStack::~IntStack()
//{
//	delete[] stackArray;
//	stackArray = nullptr;
//}
//
//IntStack::IntStack(size_t size)
//{
//	if (size > 0)
//	{
//		initializeStack(size);
//	}
//	else
//	{
//		cout << "Size of stack cannot be -ve" << endl;
//	}
//}
//
//bool IntStack::isFull()
//{
//	if (top == stackSize - 1)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool IntStack::isEmpty()
//{
//	if (top == -1)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//void IntStack::push(int data)
//{
//	if (isFull())
//	{
//		cout << "Stack overflow -> Value " << data << " has NOT been pushed to stack" << endl;
//	}
//	else
//	{
//		top++;
//		stackArray[top] = data;
//	}
//}
//
//int IntStack::pop(int &value)
//{
//	if (isEmpty())
//	{
//		cout << "Stack underflow -> cannot pop from empty stack" << endl;
//		value = INT_MIN;
//		return value;
//	}
//	else
//	{
//		value = stackArray[top];
//		top--;
//		return value;
//	}
//}
//
//int IntStack::topElement()
//{
//	if (!isEmpty())
//	{
//		return stackArray[top];
//	}
//	else
//	{
//		cout << "Stack underflow (Empty)" << endl;
//		return INT_MIN;
//	}
//}
//
//void IntStack::reverseStack()
//{
//	int *temp = new int[stackSize];
//	int index = 0;
//	int val;
//	while (!isEmpty())
//	{
//		temp[index] = pop(val);
//		index++;
//	}
//	int val1 = index;
//	index = 0;
//	while (!isFull() && index < val1)
//	{
//		push(temp[index]);
//		index++;
//	}
//	delete temp;
//	temp = nullptr;
//}