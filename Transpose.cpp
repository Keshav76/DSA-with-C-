#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of square matrix: ";
    cin>>n;
    int a[n][n];
    cout<<"Enter matrix elements: ";
    for(int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            cin>>a[i][j];
    cout<<"Matrix: \n";
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (i > j)
                swap(a[i][j], a[j][i]);
        }
    }
    cout<<"Transpose of the matrix:\n";
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}