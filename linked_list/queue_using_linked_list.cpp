#include <iostream>
using namespace std;
struct Node
{
    string data;
    Node *link;
    Node()
    {
        link = NULL;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
            return true;
        else
            return false;
    }
    void enqueue()
    {
        Node *temp = new Node;
        cout << "Enter data to enqueue: ";
        cin >> temp->data;
        if (isEmpty())
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->link = temp;
            rear = temp;
        }
    }
    void dequeue()
    {
        Node *temp = NULL;
        if (isEmpty())
        {
            cout << "QUEUE UNDERFLOW!!!\n";
            return;
        }
        else
        {
            if (front == rear)
            {
                temp = front;
                front = NULL;
                rear = NULL;
            }
            else
            {
                temp = front;
                front = front->link;
            }
            cout << "dequeued: " << temp->data << endl;
            delete temp;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "the queue is empty\n";
            return;
        }
        else
        {
            Node *temp = new Node;
            temp = front;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->link;
            }
            cout << endl;
        }
    }
};
int main()
{
    Queue q1;
    string command;
    while (command != "stop")
    {
        cout << "Enter a command(enqueue, dequeue, display, stop): \n";
        cin >> command;
        if (command == "enqueue")
            q1.enqueue();
        else if (command == "dequeue")
            q1.dequeue();
        else if (command == "display")
            q1.display();
    }
    if (command == "stop")
    {
        cout << "final queue: \n";
        q1.display();
    }

    return 0;
}