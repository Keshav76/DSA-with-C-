#include <iostream>
using namespace std;
class A
{
    int b;
    void func1()
    {
        cout << "func1";
    }

public:
    int a;
    void func2()
    {
        cout << "func2";
    }
};
int main()
{
    A ob;
    ob.a;
    ob.func2();
    //ob.b;       //Not allowed as b is private
    //ob.func1(); //Not allowed
    
    //These things are due to data abstraction
    //Data Encapsulation: Methods to access these data i.e. getters and setters
}