#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node *next;

	Node()
		: data(0), next(0) {}

	Node(int data)
		: data(data), next(nullptr) {}
};

class StackLL
{
private:
	bool isOperator(char c);

	bool highPrec(char op1, char op2);
	Node *top;
	void freeStack()
	{
		while (!isEmpty())
		{
			pop();
		}
	}
public:
	StackLL()
		: top(nullptr) {}

	~StackLL() { freeStack(); }
	bool isEmpty();
	void push(int data);
	int pop();
	int topElement();
	string infixToPostfix(string expression);
	string postfixToInfix(string postfixExpr);
};

int main()
{
	StackLL stack;
	string infixExpr1 = "a+b*(c^d-e)^(f+g*h)-I";
	string postfixExpr1 = stack.infixToPostfix(infixExpr1);

	cout << "Infix Expression: " << infixExpr1 << endl;
	cout << "Postfix Expression: " << postfixExpr1 << endl;

	string postfixExpr2 = postfixExpr1;
	string infixExpr2 = stack.postfixToInfix(postfixExpr1);

	cout << "Postfix Expression: " << postfixExpr2 << endl;
	cout << "Infix Expression: " << infixExpr2 << endl;


	system("pause");
	return 0;
}

bool StackLL::isEmpty()
{
	if (top == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void StackLL::push(int data)
{
	Node *newNode = new Node(data);
	newNode->next = top;
	cout << "Pushed " << data << endl;
	top = newNode;
}

int StackLL::pop()
{
	if (!isEmpty())
	{
		Node *temp = top;
		top = top->next;
		temp->next = nullptr;
		int poppedVal = temp->data;
		cout << "Popped " << temp->data << endl;
		delete temp;
		return poppedVal;
	}
	else
	{
		cout << "Stack underflow (Empty)" << endl;
		return INT_MIN;
	}
}

int StackLL::topElement()
{
	if (!isEmpty())
	{
		return top->data;
	}
	else
	{
		return INT_MIN;
	}
}

bool StackLL::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


bool StackLL::highPrec(char op1, char op2)
{
	int op1Weight, op2Weight;

	switch (op1)
	{
	case '+':
	case '-':
		op1Weight = 1;
		break;
	case '*':
	case '/':
		op1Weight = 2;
		break;
	case '^':
		op1Weight = 3;
		break;
	default:
		op1Weight = 0;
		break;
	}

	switch (op2)
	{
	case '+':
	case '-':
		op2Weight = 1;
		break;
	case '*':
	case '/':
		op2Weight = 2;
		break;
	case '^':
		op2Weight = 3;
		break;
	default:
		op2Weight = 0;
		break;
	}
	return op1Weight >= op2Weight;
}

string StackLL::infixToPostfix(string expression)
{
	stack<char> operatorStack;
	string postfixStr = "";

	for (char c : expression)
	{
		if (isalnum(c))
		{
			postfixStr += c;
		}
		else if (c == '(')
		{
			operatorStack.push(c);
		}
		else if (c == ')')
		{
			while (!operatorStack.empty() && operatorStack.top() != '(')
			{
				postfixStr += operatorStack.top();
				operatorStack.pop();
			}

			if (!operatorStack.empty() && operatorStack.top() == '(')
			{
				operatorStack.pop();
			}
		}
		else if (isOperator(c))
		{
			while (!operatorStack.empty() && operatorStack.top() != '(' && highPrec(operatorStack.top(), c))
			{
				postfixStr += operatorStack.top();
				operatorStack.pop();
			}

			operatorStack.push(c);
		}
	}

	while (!operatorStack.empty())
	{
		postfixStr += operatorStack.top();
		operatorStack.pop();
	}
	return postfixStr;
}

string StackLL::postfixToInfix(string postfixExpr)
{
	stack<string> operandStack;
	for (char c : postfixExpr)
	{
		if (isalpha(c))
		{
			string operand(1, c);
			operandStack.push(operand);
		}
		else if (isOperator(c))
		{
			string operand2 = operandStack.top();
			operandStack.pop();
			string operand1 = operandStack.top();
			operandStack.pop();

			string infix = "(" + operand1 + c + operand2 + ")";
			operandStack.push(infix);
		}
	}
	return operandStack.top();
}