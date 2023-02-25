#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[], int n, int v)
{
    for (int i = 0; i < n; i ++)
    {
        if (a[i] == v)
            return i;
    }
    return -1;
}

int binarySearch(int a[], int n, int v)
{
    int l = 0, u = n-1, m;
    while (l <= u)
    {
        m = (l + u)/2;
        if (a[m] == v)
            return m;
        else if (a[m] > v)
            u = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main()
{   
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    int a[n], maxNo = INT_MIN, sum = 0, minNo = INT_MAX,v, index;
    cout<<"Enter elements:- \n";
    for (int i = 0; i < n; i ++)
    {
        cin>>a[i];
        sum += a[i];
        maxNo = max(a[i], maxNo);
        minNo = min(a[i], minNo);
    }
    cout<<"Max: "<<maxNo;
    cout<<"\nMin: "<<minNo;
    cout<<"\nSum: "<<sum;
    cout<<"\nEnter the number to search: ";
    cin>>v;
    index = binarySearch(a,n,v);
    if (index == -1)
        cout<<"Not Found";
    else
        cout<<"Found at "<<index + 1;
}
