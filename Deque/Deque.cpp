#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);
    dq.push_front(5);
    dq.push_front(6);
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl;
    dq.pop_front();
    dq.pop_back();
    for (auto i : dq)
    {
        cout << i << " ";
    }
}