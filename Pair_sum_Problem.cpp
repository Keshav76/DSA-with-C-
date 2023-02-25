#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements: ";
    for (int i = 0; i< n; i ++)
        cin>>a[i];
    cout<<"Enter sum value to be searced: ";
    int given_sum;
    cin>>given_sum;

    //for this algorithm to work properly, array must be sorted


    int lower = 0, upper = n-1;
    while(lower < upper)
    {
        int sum = a[lower] + a[upper];
        if (sum == given_sum)
        {
            cout<<"Found at Element:"<<lower + 1<<" + Element:"<<upper + 1;
            return 0;
        }
        else if (sum > given_sum)
            upper --;
        else    // (sun < given_sum)
            lower ++;
    }
    cout<<"No such elements found.";
    return 0;
}