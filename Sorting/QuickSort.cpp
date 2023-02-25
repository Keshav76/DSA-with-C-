#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int partition(int arr[], int s, int e)
{
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if (arr[j] < arr[e])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]);
    return i + 1;
}

void quickSort(int arr[], int s, int e)
{
    if (! (s < e))  
        return;
    int partitionIndex = partition(arr, s, e);
    quickSort(arr, s, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, e);
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}