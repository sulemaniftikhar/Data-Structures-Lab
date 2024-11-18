//#include <iostream>
//
//using namespace std;
//
//class Stack
//{
//private:
//	int top;
//	int *stackArray;
//	int stackSize;
//
//public:
//	Stack(int size);
//	bool push(int data);
//	int pop();
//	bool isEmpty();
//	int peek();
//};
//
//int main()
//{
//	cout << boolalpha;
//	Stack stack(10);
//
//	cout << "Before pushing" << endl;
//	cout << "Stack empty or not: " << stack.isEmpty() << endl;
//
//
//	// pushing stack
//	for (int i = 1; i <= 11; i++)
//	{
//		stack.push(i * 10);
//	}
//
//	cout << "After pushing" << endl;
//	cout << "Stack empty or not: " << stack.isEmpty() << endl;
//
//	cout << "Peek element: " << stack.peek() << endl;
//
//	// popping stack
//	for (int i = 1; i <= 11; i++)
//	{
//		stack.pop();
//	}
//
//	system("pause");
//	return 0;
//}
//
//Stack::Stack(int size)
//{
//	if (size > 0)
//	{
//		stackArray = new int[size];
//		top = -1;
//		stackSize = size;
//	}
//	else
//	{
//		cout << "Size of stack cannot be -ve" << endl;
//	}
//}
//
//bool Stack::push(int data)
//{
//	if (top == stackSize - 1)
//	{
//		cout << "Stack overflow -> Value " << data << " has NOT been pushed to stack" << endl;
//		return false;
//	}
//	else
//	{
//		top++;
//		stackArray[top] = data;
//		cout << "Value " << data << " has been pushed to stack" << endl;
//		return true;
//	}
//}
//
//int Stack::pop()
//{
//	if (isEmpty())
//	{
//		cout << "Stack underflow -> cannot pop from empty stack" << endl;
//		return INT_MIN;
//	}
//	else
//	{
//		cout << "Value " << stackArray[top] << " has been popped" << endl;
//		return stackArray[top--];
//	}
//}
//
//int Stack::peek()
//{
//	if (!isEmpty())
//	return
//		stackArray {[top];
//	}
//	else
//	{
//		cout << "Stack underflow (Empty)" << endl;
//		return INT_MIN;
//	}
//}
//
//bool Stack::isEmpty()
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