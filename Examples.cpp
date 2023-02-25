#include<iostream>
using namespace std;
int main()
{   //To find that a number is armstrong or not
    cout<<"************************************";
    int n, store, sum = 0;
    cout<<"\nEnter a number: ";
    cin>>store;
    n = store;
    for (;;)
    {
        int rem = n % 10;
        sum = sum + rem * rem * rem;
        if (n / 10 == 0)
            break;
        n /= 10;
    }
    cout<<  ((sum == store) ? "Armstrong" : "Not Armstrong");

    //To reverse a number
    cout<<"\n************************************";
    cout<<"\nEnter another number: ";
    cin>>n;
    store = n;
    int temp = 0;
    for( ; ; )
    {
        temp *= 10;
        temp = temp + n % 10;
        if(n / 10 == 0)
            break;
        n = n / 10;
    }
    cout<<"Reverse of the number "<<store<<" is : "<<temp;

    //to print ascii
    cout<<"\n************************************";
    char c;
    cout<<"\nEnter any character: ";
    cin>>c;
    cout<<"ASCII of "<<c<<" is "<<(int)c;

    //to print all factors
    cout<<"\n************************************";
    cout<<"\nEnter any number: ";
    cin>>n;
    cout<<"Factors are: ";
    for (int i = 1; i <= n; i ++)
        if (n % i == 0)
            cout<<i<<" ";
}