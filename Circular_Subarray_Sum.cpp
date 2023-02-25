#include<iostream>
using namespace std;
int kadane(int a[], int n)
{
    int kadaneSum = 0, max_sum = INT_MIN;
    for (int i = 0; i < n; i ++)
    {
        kadaneSum += a[i];
        kadaneSum = max(kadaneSum,0);
        max_sum = max(kadaneSum, max_sum);
    }
    return max_sum;
}
int main()
{
    int n;
    cout<<"Enter array length: ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements: ";
    for (int i = 0; i < n; i ++)
        cin>>a[i];
    int wrapSum = 0, noWrapSum = 0, total_sum = 0; 
    noWrapSum = kadane(a, n);


    //wrap sum = total sum - (sum of non contributing elements)
    //wrap sum = total sum - (- (max subarray sum of negative of that array))
    //wrap sum = total sum - (- kadane(negative array) );
    
    
    for (int i = 0; i < n; i ++)
    {
        total_sum += a[i];
        a[i] = -a[i];
    }
    wrapSum = total_sum + kadane(a,n);
    cout<<"Max Circular Subarray Sum : "<<max(wrapSum,noWrapSum);
    return 0;
}