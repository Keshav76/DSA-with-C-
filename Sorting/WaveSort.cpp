// a1 >= a2 <= a3 >= a4 <= a5 >= a6 ......
// 11      23        19         34
//     2        17        12

#include<iostream>
using namespace std;
void waveSort(int arr[], int n)
{
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] > arr[i - 1])
        {
            swap(arr[i], arr[i - 1]);
        }
        if (i <= n - 2 and arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i  ++)
    {
        cin>>arr[i];
    }
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] > arr[i-1])
        {
            swap(arr[i],arr[i-1]);
        }
        if (i <= n-2 and arr[i] > arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    waveSort(arr,n);
    for (auto ele:arr)
    {
        cout << ele << " ";
    }
    cout << endl;
}