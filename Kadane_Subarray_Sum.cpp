#include <iostream>
using namespace std;
int main()
{

    int n;
    cout << "Enter array size: ";
    cin >> n;
    int a[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Kadane's algorithm
    int kadane_sum = 0, max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        kadane_sum += a[i];
        kadane_sum = max(kadane_sum, 0);
        max_sum = max(kadane_sum, max_sum);
    }
    cout << "Max Subarray Sum = " << max_sum;
}