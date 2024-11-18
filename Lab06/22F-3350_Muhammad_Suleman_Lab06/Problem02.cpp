#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
	int top;
	char *stackArray;
	int stackSize;

public:
	Stack(int size);
	bool push(char data);
	char pop();
	bool isEmpty();
	char peek();
	int precedence(char op);
	string convertToPostfix(string infix);
};

int main()
{
	Stack stack(10);

	string infixExpression;
	cout << "Enter an infix expression: ";
	getline(cin, infixExpression);

	string postfixExpression = stack.convertToPostfix(infixExpression);

	cout << "Postfix expression: " << postfixExpression << endl;

	system("pause");
	return 0;
}

Stack::Stack(int size)
{
	if (size > 0)
	{
		stackArray = new char[size];
		top = -1;
		stackSize = size;
	}
	else
	{
		cout << "Size of stack cannot be negative" << endl;
	}
}

bool Stack::push(char data)
{
	if (top == stackSize - 1)
	{
		return false;
	}
	else
	{
		top++;
		stackArray[top] = data;
		return true;
	}
}

char Stack::pop()
{
	if (isEmpty())
	{
		cout << "Stack underflow -> Cannot pop from empty stack" << endl;
		return '\0';
	}
	else
	{
		return stackArray[top--];
	}
}

char Stack::peek()
{
	if (!isEmpty())
	{
		return stackArray[top];
	}
	else
	{
		cout << "Stack underflow (Empty)" << endl;
		return '\0';
	}
}

bool Stack::isEmpty()
{
	return top == -1;
}

int Stack::precedence(char op)
{
	if (op == '+' || op == '-')
	{
		return 1;
	}
	else if (op == '*' || op == '/')
	{
		return 2;
	}
	else if (op == '^')
	{
		return 3;
	}
	else
	{
		return -1;
	}
}

string Stack::convertToPostfix(string infix)
{
	string postfix;
	int infixLength = infix.length();

	for (int i = 0; i < infixLength; i++)
	{
		if (infix[i] == ' ' || infix[i] == '\t')
		{
			continue;
		}
		else if (isdigit(infix[i]))
		{
			while (i < infixLength && isdigit(infix[i]))
			{
				postfix += infix[i++];
			}
			postfix += ' ';
			i--;
		}
		else if (infix[i] == '(')
		{
			push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (!isEmpty() && peek() != '(')
			{
				postfix += pop();
				postfix += ' ';
			}
			if (!isEmpty() && peek() == '(')
			{
				pop();
			}
		}
		else
		{
			while (!isEmpty() && peek() != '(' && (precedence(infix[i]) <= precedence(peek())))
			{
				postfix += pop();
				postfix += ' ';
			}
			push(infix[i]);
		}
	}
	while (!isEmpty())
	{
		postfix += pop();
		postfix += ' ';
	}
	return postfix;
}