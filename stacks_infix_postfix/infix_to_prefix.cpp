#include <iostream>
#include <stack>
#include <algorithm>
#include "convert_prefix.h"
using namespace std;

string infix_to_prefix(stack<char> stack, string infix);

int main()
{
    string infix, prefix;
    stack<char> stack;
    cout << "Enter a string to convert a infix expression to prefix: \n";
    cin >> infix;
    prefix = infix_to_prefix(stack, infix);

    cout << "Prefix expression = \n"
         << prefix << endl;
}
string infix_to_prefix(stack<char> stack, string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());
    int length = infix.length();
    for (int i = 0; i < length; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    prefix = convert(infix, stack);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}