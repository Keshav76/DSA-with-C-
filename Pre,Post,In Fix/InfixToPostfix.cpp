#include <iostream>
#include <stack>
#include <math.h>
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
string InfixToPostfix(string s)
{
    stack<char> st;
    st.push('!');
    string res = "";
    for (auto i : s)
    {
        if (i >= 'a' && i <= 'z')
        {
            res += i;
        }
        else if (i == '(')
        {
            st.push(i);
        }
        else if (i == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (precedence(st.top()) >= precedence(i))
            {
                res += st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while (st.top() != '!')
    {
        res += st.top();
        st.pop();
    }
    return res;
}
int main()
{
    cout << InfixToPostfix("(a-b/c)*(a/k-l)") << endl;
}