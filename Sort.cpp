#include<iostream>
using namespace std;
void SelectionSort(int a[], int n)
{
    //SELECTION SORT : search for smallest number ; swap with Ith term and repeat for array from (i+1) to n
    int minPos;
    for (int i = 0 ; i < n - 1; i ++)
    {
        minPos = i;
        for (int j = i; j < n; j ++)
        {
            if (a[minPos] > a[j])
                minPos = j;
        }
        int temp = a[minPos];
        a[minPos] = a[i];
        a[i] = temp;
    }
}
void BubbleSort(int a[], int n)
{
    //BUBBLE SORT : Here we swap adjacent values if they are in wrong order; i : 0 -> n-1;  j: 0 -> n-i-1
    for (int i = 0; i < n-1; i ++)
    {
        for (int j = 0; j < n-i-1; j ++)
        { 
            if (a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i ++)
    {
        int current = a[i];
        int j = i - 1;
        while (a[j] > current && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = current;
    }
}
int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements: ";
    for (int i = 0; i < n; i ++)
        cin>>a[i];
    InsertionSort(a,n);
    for (int i = 0; i < n; i ++)
        cout<<a[i]<<" ";
}