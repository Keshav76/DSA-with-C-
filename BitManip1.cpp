#include<iostream>
using namespace std;

bool PowerOf2(int n)
{
    // int noOfZeroes = __builtin_clz(n) + __builtin_ctz(n);
    // return (noOfZeroes == 31) ? true : false;
    //Other Way : Shorter
    return !(n & (n-1));
}
int oneCount(int n)
{
    int count;
    while (n)
    {
        n = (n & (n-1));
        count ++;
    }
    return count;
}
void printSubsets(char arr[], int n)
{
    for (int i = 0; i < (1<<n); i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (i & (1<<j))
            cout << arr[j] << " "; 
        }
        cout << endl;
    }
}
void CountingBits(int n)
{
    int *arr;
    for (int i = 0; i <= n; i ++)
    {
        cout << oneCount(i) << " ";
    }cout << endl;
}
bool PowerOf4(int n)
{
    int a = __builtin_clz(n);
    int b = __builtin_ctz(n);
    if (a+b == 31 && b % 2 == 0) return true;
    return false;
}
int main()
{
    cout << PowerOf2(1024) << endl;
    cout << oneCount(56);            //1 1 1 0 0 0
    char x[] = {'a', 'b', 'c'};
    printSubsets(x,3);
    CountingBits(2);
    cout << PowerOf4(4) << endl;
}