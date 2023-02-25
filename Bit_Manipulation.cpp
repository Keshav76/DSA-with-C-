#include<iostream>
#include<math.h>
using namespace std; 

int getBit(int n, int pos)              //Returns value of bit at given pos
{
    return (n & (1<<pos)) != 0;
}
int setBit(int n, int pos)              //Returns number after setting bit = 1 at given pos
{
    return (n | (1<<pos));
}
int clearBit(int n, int pos)            //Returns number after setting bit = 0 at given pos
{
    return (n & (~(1<<pos)));
}
int updateBit(int n, int pos, bool res) //Returns number after setting bit = res at given pos
{
    return (res == 0) ? clearBit(n,pos) : setBit(n,pos);
}
int toggleBit(int n, int pos)           //Returns number after inverting bit at given pos
{
    return (n ^ (1 << pos));
}
int XorFrom1toN(int n)
{
    switch (n % 4)
    {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
        default: return INT_MIN;
    }                
}
int XorEqualSum(int n)
{
    int count;
    while (n != 0)
    {
        count += !getBit(n, 0);
        n = n>>1;
    }
    return (1<<count);
}
int reverseBit(int n)
{
    return 1;
}
int XorOfAllSubarray(int arr[], int size)
{
    return (size == 1) ? arr[0] : 0;
}
void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
int flipBit(int n)
{
    int noOfBits = 32 - __builtin_clz(n);
    int t = pow(2,noOfBits) - 1;
    return t - n;
}
int setBitNumber(int n)
{
    int temp = 31 - __builtin_clz(n);
    return 1<<temp;
}
int Hamming_Distance(int n, int m)
{
    return __builtin_popcount( n ^ m );
}
unsigned int reverseBits(unsigned int n)
{
    unsigned int a[32], res = 0;
    for (int i = 0; i < 32; i ++)
    {
        a[31 - i] = getBit(n, i);
    }
    for (int i = 0; i < 32; i ++)
    {
        res += a[i] * pow (2,i);
    }
    return res;
}
int main()
{
    cout << getBit(9,2) << endl;
    cout << setBit(9,2) << endl;
    cout << clearBit(13,2) << endl;
    cout << updateBit(13,2,1) << endl;
    cout << updateBit(13,2,0) << endl;
    cout << toggleBit(8,3) << endl;
    cout << XorFrom1toN(6) << endl;
    cout << Hamming_Distance(4,1) << endl;
    cout << XorEqualSum(17) << endl;
    int a[] = {34};
    cout << XorOfAllSubarray(a, 1) << endl;
    cout << __builtin_clz(5) << endl;
    cout << __builtin_ctz(4) << endl;
    cout << __builtin_popcount(INT_MAX) << endl;
    int x = 12, y = 1254;
    swap(&x, &y);
    cout << x << " " << y << endl;
    cout << flipBit(23) << endl;
    cout << setBitNumber(25) << endl;
    cout << reverseBits(1) << endl;
}