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
    void insert_start(string value);
    void insert_custom(string value, int position);
    void delete_last();
    void delete_first();
    void delete_custom(int position);
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
void List::insert_start(string value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->link = head;
    head = temp;
}
void List::insert_custom(string value, int position)
{
    if (head == NULL)
    {
        cout << "No head element";
        return;
    }
    Node *temp = new Node;
    Node *previous = new Node;
    Node *current = new Node;
    temp->data = value;
    current = head;
    for (int i = 1; i < position; i++)
    {
        previous = current;
        current = current->link;
    }
    previous->link = temp;
    temp->link = current;
}
void List::delete_last()
{
    Node *previous = new Node;
    Node *current = new Node;
    current = head;
    while (current->link != NULL)
    {
        previous = current;
        current = current->link;
    }
    tail = previous;
    previous->link = NULL;
    delete current;
}
void List::delete_first()
{
    Node *temp = new Node;
    temp = head;
    head = head->link;
    delete temp;
}
void List::delete_custom(int position)
{
    Node *previous = new Node;
    Node *current = new Node;
    current = head;
    for (int i = 1; i < position; i++)
    {
        previous = current;
        current = current->link;
    }
    previous->link = current->link;
    delete current;
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
    int pos;
    cout << "COMMAND CODES:\n"
         << "To insert at the end enter : 0 \n"
         << "To insert at the start enter : 1 \n"
         << "To insert at custom location enter : 2 \n"
         << "To delete at the end enter : 3 \n"
         << "To delete at the first enter : 4 \n"
         << "To delete at custom location enter : 5 \n"
         << "To display enter : 6 \n"
         << "To end the list and display enter: end\n"
         << endl;

    command = '0';
    while (command != "end")
    {
        if (command == "0")
        {
            cout << "Enter the data u want to input: ";
            cin >> value;
            list.insert_end(value);
        }
        else if (command == "1")
        {
            cout << "Enter the data u want to input: ";
            cin >> value;
            list.insert_start(value);
        }
        else if (command == "2")
        {
            cout << "Enter the data u want to input: ";
            cin >> value;
            cout << "Enter the position at which u want to input: ";
            cin >> pos;
            list.insert_custom(value, pos);
        }
        else if (command == "3")
        {
            cout << "last element deleted\n";
            list.delete_last();
        }
        else if (command == "4")
        {
            cout << "first element deleted\n";
            list.delete_first();
        }
        else if (command == "5")
        {
            cout << "Enter the position u want to delete: ";
            cin >> pos;
            list.delete_custom(pos);
        }
        else if (command == "6")
        {
            list.display();
        }

        cout << "Enter the next command: ";
        cin >> command;
    }
    cout << "final list is:\n";
    list.display();
    return 0;
}