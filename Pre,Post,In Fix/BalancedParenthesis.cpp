#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    stack<char> st;
    cout << "Enter string of brackets: ";
    cin >> s;
    
    for (auto i:s)
    {
        if (i == '(' || i == '{' || i == '[')
        {
            st.push(i);
        }
        else if (i == ')' || i == '}' || i == ']')
        {
            if (!st.empty() && (st.top() == '(' && i != ')' || st.top() == '{' && i != '}' || st.top() == '[' && i != ']'))
            {
                cout << "False";
                return 0;
            }
            st.pop();
        }
        else
        {
            cout << "Enter only brackets.\n";
            return 0;
        }
    }
    if (!st.empty())
    {
        cout << "False";
        return 0;
    }
    cout << "True";
}