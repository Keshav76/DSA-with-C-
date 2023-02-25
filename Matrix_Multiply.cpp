#include<iostream>
using namespace std;
int main()
{
    int n1,n2,n3;
    cout<<"Enter matrix 1 size: ";
    cin>>n1>>n2;
    cout<<"Enter matrix 2 size: "<<n2;
    cin>>n3;
    int a[n1][n2], b[n2][n3];
    for (int i = 0; i < n1; i ++)       //inputing matrix 1
        for (int j = 0; j < n2; j ++)
            cin>>a[i][j];

    for (int i = 0; i < n2; i ++)       //inputing matrix 2
        for (int j = 0; j < n3; j ++)
            cin>>b[i][j];

    cout<<"Matrix 1: \n";
    for (int i = 0; i < n1; i ++)
    {
        for (int j = 0 ; j < n2; j ++)
            cout<<a[i][j]<<" ";
        cout<<endl; 
    }
    cout<<"Matrix 2: \n";
    for (int i = 0; i < n2; i ++)
    {
        for (int j = 0 ; j < n3; j ++)
            cout<<b[i][j]<<" ";
        cout<<endl; 
    }
    int c[n1][n3];

    //code goes here

    for (int i = 0; i < n1; i ++)
    {
        for (int j = 0; j < n3; j ++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n2; k ++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout<<"Matrix 1 * Matrix 2: \n";
    for (int i = 0; i < n1; i ++)
    {
        for (int j = 0 ; j < n3; j ++)
            cout<<c[i][j]<<" ";
        cout<<endl; 
    }
}