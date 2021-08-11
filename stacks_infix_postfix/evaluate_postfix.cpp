#include <iostream>
#include <stack>
#include <math.h>
#include "convert_prefix.h"
#define MAX 10
using namespace std;
string question(string detect);
int num_variables_postfix(string postfix);
float compute_postfix(string postfix, float variable_values[]);
float calc(float top, float below_top, char op);
int main()
{
    string detect;
    string postfix;
    int num_variables;
    cout << "Type CONVERT to convert infix to postfix/ Type CALC to directly calculate postfix \n";
    cin >> detect;
    postfix = question(detect);
    cout << "Postfix = " << postfix << endl;
    num_variables = num_variables_postfix(postfix);
    cout << "Number of variables = " << num_variables << endl;
    float variables[num_variables];
    cout << "Enter the values of variables in order : \n";
    for (int i = 0; i < num_variables; i++)
    {
        cin >> variables[i];
    }
    float result = compute_postfix(postfix, variables);
    cout << " answer = " << result << endl;
    return 0;
}
float compute_postfix(string postfix, float variable_values[])
{
    float top, below_top, push, answer;
    int var = 0;
    stack<char> evaluation;
    for (int i = 0; i < postfix.size(); i++)
    {
        if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z'))
        {
            evaluation.push(variable_values[var]);
            var += 1;
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
        {
            top = evaluation.top();
            evaluation.pop();
            // cout << top << endl;
            below_top = evaluation.top();
            evaluation.pop();
            // cout << below_top << endl;
            push = calc(top, below_top, postfix[i]);
            // cout << push << endl;
            evaluation.push(push);
        }
    }
    answer = evaluation.top();
    return answer;
}
string question(string detect)
{
    string infix;
    string post;
    stack<char> conversion;
    if (detect == "CONVERT")
    {
        cout << "Enter an infix to convert to postfix: \n";
        cin >> infix;
        post = convert(infix, conversion);
    }
    else if (detect == "CALC")
    {
        cout << "Enter a postfix to calculate \n";
        cin >> post;
    }
    return post;
}

int num_variables_postfix(string postfix)
{
    int count = 0;
    for (int i = 0; i < postfix.size(); i++)
    {
        if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z'))
        {
            count += 1;
        }
    }
    return count;
}
float calc(float top, float below_top, char op)
{
    if (op == '+')
        return below_top + top;
    else if (op == '-')
        return below_top - top;
    else if (op == '^')
        return pow(below_top, top);
    else if (op == '*')
        return below_top * top;
    else if (op == '/')
        return below_top / top;
    else
        return 0;
}