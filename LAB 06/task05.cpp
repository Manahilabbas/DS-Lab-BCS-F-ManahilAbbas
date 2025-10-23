#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Stack
{
public:
    char *arr;
    int capacity;
    int top;

    Stack(int cap = 0)
    {
        capacity = cap;
        top = -1;
        arr = new char[capacity];
    }

    ~Stack()
    {
        delete[] arr;
        arr = nullptr;
    }

    void push(char n)
    {
        if (top == capacity - 1)
        {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = n;
    }

    char pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek()
    {
        if (top < 0)
            return '\0';
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

// Function to return precedence of operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix)
{
    string postfix = "";
    Stack s(infix.length());

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        // If operand, add it to output
        if (isdigit(c))
        {
            while (i < infix.length() && isdigit(infix[i]))
            {
                postfix += infix[i];
                i++;
            }
            postfix += ' '; // add space separator
            i--;            // adjust for loop increment
        }

        // If '(' push to stack
        else if (c == '(')
            s.push(c);

        // If ')' pop until '('
        else if (c == ')')
        {
            while (!s.empty() && s.peek() != '(')
            {
                postfix += s.pop();
            }
            if (!s.empty())
                s.pop(); // remove '('
        }

        // If operator
        else
        {
            while (!s.empty() && precedence(c) <= precedence(s.peek()))
            {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators
    while (!s.empty())
        postfix += s.pop();

    return postfix;
}

double evaluatePostfix(const string &postfix)
{
    Stack val(100);
    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        // Skip spaces
        if (c == ' ')
            continue;

        // If operand
        else if (isdigit(c))
        {
            double num = 0;
            while (i < postfix.length() && isdigit(postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            val.push(num);
            i--; // adjust
        }

        // Operator
        else
        {
            double val2 = val.pop();
            double val1 = val.pop();

            switch (c)
            {
            case '+':
                val.push(val1 + val2);
                break;
            case '-':
                val.push(val1 - val2);
                break;
            case '*':
                val.push(val1 * val2);
                break;
            case '/':
                val.push(val1 / val2);
                break;
            case '^':
                val.push(pow(val1, val2));
                break;
            }
        }
    }

    return val.pop();
}

void solution()
{
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    double result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;
}

int main()
{
    solution(); 
    return 0;
}
