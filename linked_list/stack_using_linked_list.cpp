#include <iostream>
using namespace std;
struct Node
{
    string data;
    Node *next;
};

class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }

    void push(Node *n)
    {
        if (isEmpty())
        {
            top = n;
        }
        else
        {
            Node *temp = top;
            top = n;
            n->next = temp;
        }
        cout << "Pushed successfully\n";
    }
    Node *pop()
    {
        Node *temp = NULL;
        if (isEmpty())
        {
            cout << "Stack underflow\n";
            return temp;
        }
        else
        {
            temp = top;
            top = top->next;
            return temp;
        }
    }

    void display()
    {

        Node *temp = top;

        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Stack s;
    string data, action;

    for (int i = 0;; i++)
    {
        Node *new_node = new Node();
        cout << "Enter the action you want to perform(push/pop/display/finish): ";
        cin >> action;

        if (action == "push")
        {
            cout << "Enter the data: \n";
            cin >> data;
            new_node->data = data;
            s.push(new_node);
            cout << endl;
        }
        else if (action == "pop")
        {
            cout << "The top of the stack is :\n";
            new_node = s.pop();
            cout << "data = " << new_node->data << endl;
            cout << endl
                 << endl;
            delete new_node;
        }
        else if (action == "display")
        {
            cout << "The values in stack are as follows: \n";
            s.display();
        }
        else if (action == "finish")
        {
            cout << "The final values in stack are as follows: \n";
            s.display();
            cout << "Ending the program.....\n";
            break;
        }
    }
    return 0;
}