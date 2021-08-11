#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *link;
};

class List
{
public:
    Node *head, *tail;
    List()
    {
        head = tail = NULL;
    }
    void insert_end(string value);
    void reverse_list();
    void display();
};
void List::insert_end(string value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->link = NULL;
    if (head != NULL)
    {
        tail->link = temp; // changing link of the last element to temp
        tail = temp;       // the new temp is changed to the tail
    }
    else
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
}
void List::reverse_list()
{
    Node *previous = new Node;
    Node *current = new Node;
    Node *next = new Node;
    Node *temp = new Node;

    previous = NULL;
    current = head;

    while (current != NULL)
    {
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    head = previous;
    temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    tail = temp;
}
void List::display()
{
    Node *temp = new Node;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}

int main()
{
    List list;
    string command, value;
    for (int i = 0;; i++)
    {
        cout << "Enter Command: ";
        cin >> command;
        if (command == "add")
        {
            cout << "Enter data: ";
            cin >> value;
            list.insert_end(value);
        }
        else if (command == "reverse")
        {
            list.reverse_list();
            cout << "List reversed \n";
        }
        else if (command == "display")
        {
            list.display();
        }
        else if (command == "end")
        {
            cout << "Final list: \n";
            list.display();
            break;
        }
    }
}