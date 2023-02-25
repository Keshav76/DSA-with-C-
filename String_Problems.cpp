#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s = "asnlalnkdKJkdm'';ds";
    // transform(s.begin(), s.end(), s.begin(), ::toupper);     //using algorithm
    for (int i = 0 ; i < s.size(); i ++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = toupper(s[i]);       // or s[i] -= 32   as 'a' - 32 = 'A'
    }
    cout<<"To Capital: "<<s;

    //transform(s.begin(), s.end(), s.begin(), ::tolower);      //using algorithm
    for (int i = 0; i < s.length(); i ++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;                 //or s[i] = tolower(s[i]);
    }
    cout<<endl<<"To Small: "<<s;

    //biggest number
    string str = "5464100";
    sort (str.begin(), str.end());
    reverse(str.begin(), str.end());
    int largestNum = stoi(str);
    cout<<endl<<"Largest Number possible: "<<largestNum;

    //smallest number
    str = "5464100";
    sort(str.begin(), str.end());
    for (int i = 0; i <str.length(); i ++)
    {
        if (str[i] != '0')
        {
            char temp = str[i];
            str[i] = str[0];
            str[0] = temp;
            break;
        }
    }
    int smallestNumber = stoi(str);
    cout<<endl<<"Smallest Number Possible: "<<smallestNumber;

    //Most number of characters
    str = "abcdefghijklmnopqrstuvwxyz";
    int freq[26] = {0};
    for (int i = 0; i < str.length(); i ++)
    {
        freq[str[i] - 'a'] ++;
    }
    int maxF = 0;
    char maxC;
    for (int i = 0; i < 26; i ++)
    {
        if (freq[i] > maxF)
        {
            maxF = freq[i];
            maxC = i + 'a';
        }
    }
    cout<<"\nMost found char : "<<maxC<<" Times: "<<maxF;
}