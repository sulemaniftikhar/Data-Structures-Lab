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
    int evaluatePostfix(string postfix);
};

int main()
{
    Stack stack(10);

    string postfixExp;
    cout << "Enter an infix expression: ";
    getline(cin, postfixExp);

    int result = stack.evaluatePostfix(postfixExp);

    cout << "Result: " << result << endl;

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
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
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

int Stack::evaluatePostfix(string postfix)
{
    int length = postfix.length();
    for (int i = 0; i < length; i++)
    {
        if (postfix[i] == ' ' || postfix[i] == '\t')
        {
            continue;
        }
        else if (isdigit(postfix[i]))
        {
            int operand = 0;
            while (i < length && isdigit(postfix[i]))
            {
                operand = (operand * 10) + (postfix[i] - '0');
                i++;
            }
            i--;
            push(operand);
        }
        else
        {
            int operand2 = pop();
            int operand1 = pop();

            switch (postfix[i])
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            case '^':
                push(pow(operand1, operand2));
                break;
            default:
                cout << "Invalid operator" << endl;
                return 0;
            }
        }
    }
    return pop();
}