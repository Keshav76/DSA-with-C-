#include<iostream>
using namespace std;

int gcd(int a, int b)       //Euclid's Algorithm for GCD
{
    int divident = max(a,b);
    int divisor = min(a,b);
    int rem = 0;
    do 
    {   
        rem = divident % divisor;
        divident = divisor;
        divisor = rem;
    }
    while (divisor != 0);
    return divident;
}
int lcm(int a, int b)
{
    return ((a*b) / gcd(a,b));
}
int Divisibility(int n, int a, int b)     //Find no of elements divisible by a or b in limit 0 to n
{                                         
    int c1 = n / a;
    int c2 = n / b;
    int c3 = n / lcm(a, b);
    return c1 + c2 - c3;                //Uses Inclusion Exclusion Principle
}

int main()
{
    // cout << gcd(24,9) << endl;
    // cout << lcm(24, 9) << endl;
    // cout << Divisibility(40,8,4) << endl;       
    int a,b;
    cout<<"Enter:";
    cin>>a>>b;
    cout<<gcd(a,b);

}


