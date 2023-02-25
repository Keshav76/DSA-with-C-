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
        int cd = a[1] - a[0],list = 1,maxList = 2;
        for (int i = 1; i < n; i ++)
        {
            int temp = a[i] - a[i-1];
            if (temp == cd)
            {
                list += 1;
                if (list > maxList)
                    maxList = list;
            }
            else
            {
                cd = temp;
                list = 2;
            }
        }
        cout<<"Case #"<<q<<": "<<maxList<<endl;
    }
}