#include <iostream>
using namespace std;
class queueLL
{
    class node
    {
    public:
        int data;
        node *next;
        node(int val)
        {
            data = val;
            next = NULL;
        }
    } * front, *back;

public:
    queueLL()
    {
        front = NULL;
        back = NULL;
    }
    void enqueue(int val)
    {
        if (front == NULL)
        {
            back = new node(val);
            front = back;
            return;
        }
        back->next = new node(val);
        back = back->next;
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        node *deleter = front;
        front = front->next;
        delete (deleter);
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        return front == NULL;
    }
};
int main()
{
    queueLL q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(2);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    cout << "*********************\n";
    cout << q.empty() << endl;
    q.dequeue();
    cout << q.empty() << endl;
}