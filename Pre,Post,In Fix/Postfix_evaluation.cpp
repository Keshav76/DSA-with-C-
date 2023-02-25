#include<math.h>
#include<iostream>
#include<stack>
using namespace std;
int PostfixEvaluator(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i ++)
    {
        if (s[i] >= '0' and s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int ele2 = st.top();st.pop();
            int ele1 = st.top();st.pop();
            switch(s[i])
            {
                case '+':
                    st.push(ele1 + ele2);
                    break;
                case '-':
                    st.push(ele1 - ele2);
                    break;
                case '*':
                    st.push(ele1 * ele2);
                    break;
                case '/':
                    st.push(ele1 / ele2);
                    break;
                case '^':
                    st.push(pow(ele1, ele2));
                    break;
                default: 
                    cout << "Wrong Operand" << endl;
                    break;
            }
        }
    }
    return st.top();
}

int main()
{
    cout << PostfixEvaluator("623+-382/+*2^3+") << endl;
}