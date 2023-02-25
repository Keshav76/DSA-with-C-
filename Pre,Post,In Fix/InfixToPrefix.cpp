#include<bits/stdc++.h>
#define clear() printf("\033[H\033[J")
using namespace std;
int precedence(char s)
{
    switch (s)
    {
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return -1;
        break;
    }
}
string InfixToPrefix(string s)
{
    string res = "";
    stack<char> st;
    reverse(s.begin(),s.end());
    for(auto i:s)
    {
        if(i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z')
        {
            res += i;
        }
        else if(i == ')')
        {
            st.push(i);
        }
        else if (i == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(i) < precedence(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    // cout << "\033c";
    cout << InfixToPrefix("(a-b/c)*(a/k-l)") << endl;
}