#include <iostream>
#include <queue>
using namespace std;
class stack
{
    queue<int> q1;
    queue<int> q2;
    int n;
public:
    stack()
    {
        n = 0;
    }
    void push(int val)
    {
        q1.push(val);
        n++;
    }
    void pop()
    {
        if (n == 0)
        {
            cout << "Stack is empty.\n";
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        n--;
    }
    bool empty()
    {
        return n == 0;
    }
    int top()
    {
        if (n == 0)
        {
            cout << "Stack is empty.\n";
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        q1.pop();
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }
};
int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.empty() << endl;
    return 0;
}