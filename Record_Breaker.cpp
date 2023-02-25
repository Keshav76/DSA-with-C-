//asked in google kickstart
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for (int q = 1; q <= t; q ++)
    {
        int n;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; i ++)
            cin>>a[i];
        int mx = 0, count = 0;
        for (int i = 0; i < n; i ++)
        {
            if (a[i] > mx && (i == n - 1 || a[i] > a[i + 1]))
            {
                count ++;
            }
            mx = max(mx,a[i]);
        }
        cout<<"Case #"<<q<<": "<<count<<endl;
    }
}