#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack
{
private:
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == MAX - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return -1;
        }

        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack s;
    string exp;

    cout << "Enter postfix expression: ";
    cin >> exp;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        // If operand, push it into stack
        if (ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }

        // If operator, pop two operands and perform operation
        else
        {
            int b = s.pop();
            int a = s.pop();

            switch (ch)
            {
                case '+':
                    s.push(a + b);
                    break;

                case '-':
                    s.push(a - b);
                    break;

                case '*':
                    s.push(a * b);
                    break;

                case '/':
                    s.push(a / b);
                    break;

                default:
                    cout << "Invalid operator\n";
                    return 0;
            }
        }
    }

    cout << "Result = " << s.pop() << endl;

    return 0;
}