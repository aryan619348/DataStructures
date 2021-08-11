#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
string convert(string infix, stack<char> conversion_stack);
int precedence(char op);
int main()
{
    string in;
    string post;
    stack<char> conversion;
    cout << "Enter an infix to convert to postfix: \n";
    cin >> in;
    post = convert(in, conversion);
    cout << "Postfix = " << post << endl;
    return 0;
}
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '/')
        return 3;
    else
        return 0;
}
string convert(string infix, stack<char> conversion_stack)
{

    string postfix;

    for (int i = 0; i < infix.size(); i++)
    {
        if ((infix[i] > 'a' && infix[i] < 'z') || (infix[i] > 'A' && infix[i] < 'Z'))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            conversion_stack.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((conversion_stack.top() != '(') && (!conversion_stack.empty()))
            {
                postfix += conversion_stack.top();
                conversion_stack.pop();
            }
            if (conversion_stack.top() == '(')
                conversion_stack.pop();
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            if (conversion_stack.empty())
            {
                conversion_stack.push(infix[i]);
            }
            else
            {
                if (precedence(infix[i]) > conversion_stack.top())
                {
                    conversion_stack.push(infix[i]);
                }
                else if ((infix[i] == '^') && (precedence(infix[i]) == conversion_stack.top()))
                {
                    conversion_stack.push(infix[i]);
                }
                else
                {
                    while ((precedence(infix[i]) <= conversion_stack.top()) && (!conversion_stack.empty()))
                    {
                        postfix += conversion_stack.top();
                        conversion_stack.pop();
                    }
                    conversion_stack.push(infix[i]);
                }
            }
        }
    }
    while (!conversion_stack.empty())
    {
        postfix += conversion_stack.top();
        conversion_stack.pop();
    }
    return postfix;
}