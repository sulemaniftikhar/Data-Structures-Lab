//#include <iostream>
//#include <string>
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
//	bool isBalanced(string exp);
//};
//
//int main()
//{
//	StackLL stack;
//	cout << boolalpha;
//
//	string exp1 = "{[{}{}]}[()]";
//	cout << exp1 << " is balanced: " << stack.isBalanced(exp1) << endl;
//
//	string exp2 = "{{}{}}";
//	cout << exp2 << " is balanced: " << stack.isBalanced(exp2) << endl;
//
//	string exp3 = "[]{}()";
//	cout << exp3 << " is balanced: " << stack.isBalanced(exp3) << endl;
//
//	string exp4 = "{()}[)";
//	cout << exp4 << " is balanced: " << stack.isBalanced(exp4) << endl;
//
//	string exp5 = "{(})";
//	cout << exp5 << " is balanced: " << stack.isBalanced(exp5) << endl;
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
//
//bool StackLL::isBalanced(string exp)
//{
//	StackLL stack;
//	for (char c : exp)
//	{
//		if (c == '(' || c == '[' || c == '{')
//		{
//			stack.push(c);
//		}
//		else if (c == ')' || c == ']' || c == '}')
//		{
//			if (stack.isEmpty())
//			{
//				return false;
//			}
//			char top = stack.pop();
//			if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
//			{
//				return false;
//			}
//		}
//	}
//	return stack.isEmpty();
//}