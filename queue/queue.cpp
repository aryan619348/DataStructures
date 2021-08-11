#include <iostream>
#include <math.h>
#define MAX 100
using namespace std;
class Queue
{
private:
    int front;
    int rear;
    int size;
    string queue[MAX];

public:
    Queue()
    {
        front = -1;
        rear = -1;
        cout << "Enter the size of the queue: ";
        cin >> size;
    }
    bool isEmpty();
    bool isFull();
    void enqueue();
    void dequeue();
    void display();
};

bool Queue::isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}
bool Queue::isFull()
{
    if (rear == size - 1)
        return true;
    else
        return false;
}
void Queue::enqueue()
{
    string value;
    if (isFull())
    {
        cout << "The queue is full\n";
        return;
    }
    cout << "Enter the value you want to enter: ";
    cin >> value;
    if (isEmpty())
    {
        front = 0;
        rear = 0;
        queue[rear] = value;
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
}
void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "There are no elements in the queue to dequeue\n";
        return;
    }
    else if (front == rear)
    {
        cout << "The queue is now empty\n";
        front = -1;
        rear = -1;
        return;
    }
    else
    {
        front++;
    }
}
void Queue::display()
{
    if (isEmpty())
    {
        cout << "There are no elements in the queue to show\n";
        return;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}
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