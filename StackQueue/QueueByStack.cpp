#include <iostream>
#include <stack>
using namespace std;
class queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int val)
    {
        s1.push(val);
    }
    int dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        else if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int t = s2.top();
        s2.pop();
        return t;
    }
    int dequeueRecursive()
    {
        if (s1.empty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        int ele = s1.top();
        s1.pop();
        if(s1.empty())
        {
            return ele;
        }
        int ans = dequeueRecursive();
        s1.push(ele);
        return ans;
    }
    bool empty()
    {
        return s1.empty() and s2.empty();
    }
};
int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeueRecursive() << endl;
    cout << q.dequeueRecursive() << endl;
    cout << q.dequeueRecursive() << endl;
    cout << q.dequeueRecursive() << endl;    
}