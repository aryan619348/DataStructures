#include <iostream>
#include <stack>
#include "convert_prefix.h"

using namespace std;
string convert(string infix, stack<char> conversion_stack);
int precedence(char op);
int check_operator(char a);
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
