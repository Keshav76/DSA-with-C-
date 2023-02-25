#include<iostream>
#include<queue>
using namespace std;
class stack{
    queue<int> q1;
    queue<int> q2;
public:
    void push(int val)
    {
        q2.push(val);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    bool empty()
    {
        return q1.empty();
    }
};
int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
}