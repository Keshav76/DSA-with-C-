#include <iostream>
// #include<queue>    //can be used
using namespace std;
class queue
{
    int *arr;
    int front, back;

public:
    queue()
    {
        arr = new int[100];
        front = -1;
        back = -1;
    }
    void enqueue(int val)
    {
        if (back == 99)
        {
            cout << "Queue is full.\n";
            return;
        }
        if (front == -1)
        {
            front++;
        }
        back ++;
        arr[back] = val;
    }
    void dequeue()
    {
        if (front > back || back == -1)
        {
            cout << "Queue is empty.\n";
            return;
        }
        front ++;
    }
    int peek()
    {
        if (front > back || back == -1)
        {
            cout << "Queue is Empty. \n";
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        return front > back || front == -1;
    }
};

int main()
{
    queue q;
    cout << q.empty() << endl;
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(2);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
}