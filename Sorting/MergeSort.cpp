#include <iostream>
using namespace std;
int merge(int arr[], int s, int m, int e)
{
    int inv = 0;
    int n1 = m + 1 - s;
    int n2 = e - m;
    int a[n1], b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[s + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
    
        }
        else if (a[i] > b[j])
        {
            arr[k] = b[j];
            k++;
            j++;
            inv += n1 - i;
        }
    }

    for (j; j < n2; j++)
    {
        arr[k] = b[j];
        k++;
    }

    for (i; i < n1; i++)
    {
        arr[k] = a[i];
        k++;
    }
    return inv;
}
int mergeSort(int arr[], int s, int e)
{
    if (e <= s)
    {
        return 0;
    }
    int inv = 0;
    if (e > s)
    {
        int m = (e + s) / 2;
        inv += mergeSort(arr, s, m);
        inv += mergeSort(arr, m + 1, e);
        inv += merge(arr, s, m, e);
    }
    return inv;
}
int main()
{

    int n;
    cout << "Enter array size: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int inv = mergeSort(a, 0, (n - 1));
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\nNo Of Inversion = " << inv;
}