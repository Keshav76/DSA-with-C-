#include<iostream>
using namespace std;
int main()
{
    cout<<"****************************";
    int a,b,c;
    cout<<"\nEnter 3 numbers: ";
    cin>>a>>b>>c;
    a = a * a;
    b = b * b;
    c = c * c;
    if (a == b + c || b == a + c || c == a + b)
        cout<<"It is a pythagorean triplet.";
    else
        cout<<"It is not a pythagorean triplet.";
    cout<<"\n****************************";
    
    //to print sum of all sub arrays
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for (int i = 0; i < n; i ++)
        cin>>arr[i];
    for (int i = 0; i < n; i ++)
    {
        int sum = 0;
        for (int j = i; j < n; j ++)
        {
            sum += arr[j];
            cout<<sum<<" ";
        }
    }
}