#include <iostream>
using namespace std;

class stack
{
    class node
    {
    public:
        int data;
        node *next;
        node(int val, node *nex)
        {
            data = val;
            next = nex;
        }
    } * top;

public:
    stack()
    {
        top = NULL;
    }
    void push(int val)
    {
        top = new node(val, top);
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty\n";
            return;
        }
        node *deleter = top;
        top = top->next;
        delete (deleter);
    }
    int Top()
    {
        if (top == NULL)
        {
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        return top->data;
    }
    bool empty()
    {
        return top == NULL;
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.Top() << endl;
    s.pop();
    cout << s.Top() << endl;
    cout << s.empty() << endl;
}