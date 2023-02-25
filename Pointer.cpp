// * gives value of variable at the location stored in operand
// & gives address of variable 
#include<iostream>
using namespace std;

void swap(int *a, int *b)       //for pass by refernce, we should accept parameters as pointers; so we get address of variable
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 12;
    int *y = &x;
    int **z = &y;
    cout<<"x : "<<x;
    cout<<"\n*y : "<<*y;
    cout<<"\n**z : "<<**z;
    cout<<endl;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; i ++)
    {
        cout<<*(a+i)<<" ";  //pointer is pointing to i th element
    }
    cout<<endl;
    int *ptr = a;
    for (int i = 0; i < 10; i ++)
    {
        cout<<*ptr<<" ";
        ptr++;              //ptr automatically increments by 4 as it is an int pointer
    }
    int l = 1, m = 4;
    swap(l,m);              //pass by value
    cout<<endl<<l<<" "<<m;
    swap(&l,&m);            //pass by reference
    cout<<endl<<l<<" "<<m;

}