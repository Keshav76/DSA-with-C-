#include <iostream>
using namespace std;
int main()
{
    // To find max_word length
    char a[100];
    cout << "Enter a sentence: ";
    gets(a);
    int len = 0, mx = INT_MIN, i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == ' ')
        {
            mx = max(mx, len);
            len = 0;
        }
        else
        {
            len++;
        }
        i++;
    }
    mx = max(mx, len);
    cout << "Max word length is : " << mx;

    // palindrome
    int n;
    cout << "\nEnter word length: ";
    cin >> n;
    getchar();
    char w[n + 1];
    cout << "Enter the word: ";
    gets(w);
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (w[i] != w[n - i - 1])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Word is palindrome.";
    else
        cout << "Word is not palindrome.";
}