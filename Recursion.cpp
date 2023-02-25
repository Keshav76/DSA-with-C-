#include <iostream>
#include <string>
using namespace std;
bool checkArraySorted(int arr[], int n)
{
    if (n == 2)
    {
        return ((arr[1] >= arr[0]) ? true : false);
    }
    return ((arr[n - 1] >= arr[n - 2]) ? true : false) & checkArraySorted(arr, n - 1);
}
void printInDecOrder(int n) //It prints numbers in decreasing order from n
{
    if (n == 0)
    {
        return;
    }
    else
    {
        cout << n << " ";
        printInDecOrder(n - 1);
    }
}
void printInAscOrder(int n) //It prints numbers in ascending order from 1 to n
{
    if (n == 0)
    {
        return;
    }
    printInAscOrder(n - 1);
    cout << n << " ";
}
int checkFirstOccur(int arr[], int n, int key) //return first position of key in arr; return -1 if not found
{
    if (n == 0)
        return -1;
    if (*(arr) == key)
    {
        return 0;
    }
    int last = checkFirstOccur(arr + 1, n - 1, key);
    if (last == -1)
        return -1;
    return (1 + last);
}
int checkLastOccur(int arr[], int n, int key) //returns last position of key in arr; return -1 if not found
{
    if (n == 0)
        return -1;
    if (arr[n - 1] == key)
    {
        return n - 1;
    }
    return checkLastOccur(arr, n - 1, key);
}
void reverse(string n)
{
    if (n.length() == 0)
        return;
    char temp = n[0];
    reverse(n.substr(1));
    cout << temp;
    return;
}
void piTo3_14(string n)
{
    if (n.length() <= 1)
    {
        cout << n;
        return;
    }
    if (n[0] == 'p' && n[1] == 'i')
    {
        cout << "3.14";
        return piTo3_14(n.substr(2));
    }
    else
    {
        cout << n[0];
        return piTo3_14(n.substr(1));
    }
}
void TowerOfHanoi(int noOfDisks, char Source, char Destination, char Helper)
{
    if (noOfDisks == 1)
    {
        cout << "Move Disk number: " << noOfDisks << " from " << Source << " to " << Destination << endl;
        return;
    }
    TowerOfHanoi(noOfDisks - 1, Source, Helper, Destination);
    cout << "Move Disk number: " << noOfDisks << " from " << Source << " to " << Destination << endl;
    TowerOfHanoi(noOfDisks - 1, Helper, Destination, Source);
    return;
}

int main()
{
    // int a[] = {2,5,3,4,5};
    //cout << checkArraySorted(a,5) << endl;
    // printInDecOrder(10);
    // cout << endl;
    // printInAscOrder(10);
    // cout << endl;
    // cout << checkFirstOccur(a,5,1) << " " << checkLastOccur(a,5,1);
    // reverse("Keshav");
    // piTo3_14("pippxxpxixpipipppx");
    TowerOfHanoi(4, 'A', 'C', 'B');
}