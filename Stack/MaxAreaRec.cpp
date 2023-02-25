//We have to find maximum area of rectangle possible in a histogram
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    vector<int> arr = {1,1};
    for (auto i: arr)
    {
        cout << i << " ";
    }
    stack<int> st;
    vector<int> left(arr.size()), right(arr.size());
    //Iterating to find left limits of each elements
    for (int i = 0; i < arr.size(); i ++)
    {
        while (!st.empty() and arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            left[i] = 0;
        else
            left[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }
    //Iterating to find right limits of each element
    for (int i = arr.size() - 1; i >= 0; i --)
    {
        while (!st.empty() and arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            right[i] = arr.size() - 1;
        else
            right[i] = st.top() - 1;
        st.push(i);
    }
    int ans = 0;
    //Calculating max area by multiplying height and (right - left + 1);
    for (int i = 0; i < arr.size(); i ++)
    {
        ans = max (ans, arr[i] * (right[i] - left[i] + 1));
    }
    cout << endl <<ans;
}