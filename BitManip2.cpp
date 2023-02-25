#include<iostream>
using namespace std;
int findUnique(int arr[], int n)
{
    int xorp = 0;
    for (int i = 0; i < n; i ++)
    {
        xorp = xorp ^ arr[i];
    } 
    return xorp;
}
void print2Unique(int arr[], int n)
{
    int xorp = 0;
    for (int i = 0; i < n; i ++)
    {
        xorp = xorp ^ arr[i];
    }
    int i, xorStore = xorp;
    for ( i = 0; i < 32; i ++)
    {
        if ((xorp & (1<<i)))
        {
            break;
        }
    }
    for (int j = 0; j < n; j ++)
    {
        if ((arr[j] & (1<<i)))
        {
            xorp = xorp ^ arr[j];
        }
    }
    cout << xorp << " " << (xorp ^ xorStore) << endl;
}
int findUniqueIn3(int arr[], int n)
{
    int x = 0;
    for (int i = 0; i < 32; i ++)
    {
        int sum = 0;
        for (int j = 0; j < n; j ++)
        {
            sum += (((arr[j] & (1<<i)) != 0) ? 1 : 0);
        }
        x = x + ((sum % 3) * (1<<i));
    }
    return x;
}
int main()
{
    int a[] = {1,2,3,4,5,6,1,2,3,5,6};
    cout << findUnique(a,11) << endl;
    int b[] = {1,2,3,4,5,6,6,5,4,1};
    print2Unique(b,10);
    int c[] = {7,8,9,7,8,9,2,7,8,9};
    cout << findUniqueIn3(c,10) << endl; 
}