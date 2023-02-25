#include <iostream>
using namespace std;

class Student
{
    string name;
    int age;
    char gender;

public:
    Student() //Constructor : Default
    {
        cout << "\nObject Created by default constructor";
        name = "Keshav";
        age = 17;
        gender = 'M';
    }
    Student(string s, int a, char g) //Constructor : Parameterised
    {
        cout << "\nObject Created by parameterised constructor";
        name = s;
        age = a;
        gender = g;
    }
    Student(Student &s)
    {
        cout << "\nObject Created by copy constructor";
        name = s.name;
        age = s.age;
        gender = s.gender;
    }
    //We can even omit this copy constructor declaration
    //It will make a shallow copy of the other object       while after making this declaration, deep copy is made
    //Shallow copy: If their is a pointer in attribute list, it copies the same address i.e. refer to same location
    //Deep Copy: A new memory location is referenced by pointer

    //Destructor: It is called automatically after object goes out of scope,
    //it is used to delete the memory allocated in making of object
    ~Student()
    {
        cout << "\nDestructor Called.";
    }
    //Operator overloading
    bool operator==(Student s)
    {
        return name == s.name and age == s.age and gender == s.gender;
    }
    void getData()
    {
        cout << "Name: " << name << " Age: " << age << " Gender: " << gender;
    }
};
int main()
{
    Student a("KB", 15, 'M'); //By parameterised
    Student b("KB", 23, 'r');                //By default
    Student c = a;            //By Copy            we can also use Student c(a);
    cout << (c == b ? "Same" : "Not Same");
} 