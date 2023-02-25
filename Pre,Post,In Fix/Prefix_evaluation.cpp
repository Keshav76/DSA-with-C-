#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
int PrefixEvaluator(string s)
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' and s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int ele1 = st.top();st.pop();
            int ele2 = st.top();st.pop();
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
    cout << PrefixEvaluator("-+7*45+20") << endl;
}