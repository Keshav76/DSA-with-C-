#include<iostream>
using namespace std;
void PrimeTillNumber(int n)
{
    int arr[n + 1] = {0};
    for (int i = 2; i <= n; i ++)
    {
        if (arr[i] == 0)
        {
            for (int j = i*i; j <= n; j += i)
            {
                arr[j] = 1;
            }
        }
        if (i*i > n)
        break;
    }
    for (int i = 2; i <=n; i ++)
    {
        if (arr[i] == 0)
        cout << i << " ";
    }
    cout << endl;
}
void PrimeFactors(int n)
{
    int spf[10000] = {0};
    for (int i = 2; i <= 10000; i ++)        //creates an array till 10000 with values = smallest prime factor
    {
        if (spf[i] == 0)
        {   spf[i] = i;
            for (int j = i*i; j <= 10000; j += i)
            {
                if (spf[j] == 0)
                spf[j] = i;
            }
        }
        if (i * i > 10000)
        break;
    }
    while (n != 1)
    {
        cout << spf[n] << " ";
        n = n / spf[n];
    }
    cout << endl;
}
void PrimeInRange(int m, int n)
{
    int arr[n + 1] = {0};
    for (int i = 2; i <= n; i ++)
    {
        if (arr[i] == 0)
        {
            for (int j = i*i; j <= n; j += i)
            {
                arr[j] = 1;
            }
        }
        if (i*i > n)
        break;
    }
    for (int i = m; i <=n; i ++)
    {
        if (arr[i] == 0)
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    int a;
    cout << "Enter a number to print prime till it: ";
    cin >> a;
    PrimeTillNumber(a);

    cout << "Enter a number to print prime factors: ";
    cin >> a;
    PrimeFactors(a);

    int b;
    cout << "Enter range to print prime numbers within it (Limit Start _ Limit End): ";
    cin >> a >> b;
    PrimeInRange(a,b);
}