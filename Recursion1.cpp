#include<iostream>
using namespace std;
string Keypad[] = {"._+-*/!@#$%^&()", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string RemoveDuplicates (string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char temp = s[0];
    string prevAns = RemoveDuplicates(s.substr(1));
    if (prevAns[0] == temp)
    {
        return prevAns;
    }
    else
    {
        return (temp + prevAns);
    }
}
string ShiftX (string s, int index = 0)
{
    if (s.length() == index)
    {
        return "";
    }
    char temp = s[index];
    string ans = ShiftX (s, index + 1);
    if  (temp == 'x' || temp == 'X')
    return ans + temp;
    return temp + ans;

}
void printSubStrings (string s, string ans = "", int index = 0)
{
    if (s.length() == index)
    {
        cout << ans << endl;
        return;
    }
    char temp = s[index];
    printSubStrings(s,ans,index + 1);
    printSubStrings(s,(ans+temp), index + 1);
    return;
}
void printSubStrWithASCII (string s, string ans = "", int index = 0)
{
    if (s.length() == index)
    {
        cout << ans << endl;
        return;
    }
    char temp = s[index];
    printSubStrWithASCII (s, ans, index + 1);
    printSubStrWithASCII (s, ans+temp, index + 1);
    printSubStrWithASCII (s, ans+to_string((int)temp), index + 1);
}
void KeypadCombination (string s, string ans = "", int index = 0)
{
    if (s.length() == index)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[index];
    string str = Keypad[ch - '1'];
    for (int i = 0; i < str.length(); i ++)
    {
        KeypadCombination(s,ans+str[i],index + 1);
    }
}
int main()
{
    cout << RemoveDuplicates("abceeeeeddddddddddddddd") << endl;
    cout << ShiftX ("xhjhsazjhjhjhuzhxxxjhhuxgugxgugx") << endl;
    printSubStrings ("ABC");
    printSubStrWithASCII ("AB");
    KeypadCombination ("82");

}