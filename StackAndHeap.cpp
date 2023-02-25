// Stack: Normal memory allocation
/*
int a[10];      //a normal array declaration
int b;          //a variable is declared normally
*/

// Heap: Dynamic memory allocation

#include <iostream>
using namespace std;
int main()
{
    int a = 10;      // a normal stack declaration
    int *p;          // declaring a pointer
    p = new int(15); // creating a new int located at address in p ; value in bracket is assigned to variable  defalut is 0
    *p = 10;         // changing value of the created variable to 10
    delete (p);      // deleting only the integer variable
    p = NULL;        // deactivating the pointer

    p = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // declaring a 1d array with initial values (in braces)
    for (int i = 0; i < 10; i++)                    // printing it
    {
        cout << *(p + i) << " ";
    }
    delete (p);
    p = NULL;
    cout << endl;
    // pointer can be refered as array
    int **ptr;          // For 2d array; we use double pointer as we need to store pointer in pointer
    ptr = new int *[3]; // creating an array, of size 3, of type int pointer
    for (int i = 0; i < 3; i++)
        *(ptr + i) = new int[3]; // assigning an array to each pointer of the pointer array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            *(*(ptr + j) + i) = 5; // accessing values can be done by :: *(*(pointer+coloumn)+row)
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << *(*(ptr + j) + i) << " ";
    }

    delete (ptr);
    ptr = NULL;
}