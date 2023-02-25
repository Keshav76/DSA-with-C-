#include<iostream>
using namespace std;
#define n 100
class stack
{
    int *arr;
    int top;
    public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int val)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = val;
    }
    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Is Empty\n";
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return INT_MIN;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    cout << s.Top() << endl;
    s.pop();
    cout << s.Top() << endl;
    cout << s.empty() << endl;
}