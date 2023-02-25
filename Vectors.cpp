#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3}; //Assigning initial values
    
    v.push_back(1);
    v.push_back(3);
    v.push_back(4); //adding more values

    //Printing Techniques
    for (int i = 0; i < v.size(); i++) //By Simple Looping
    {
        cout << v[i] << " ";
    }
    cout << endl;

    vector<int>::iterator i;               //Making Iterator of type int
    for (i = v.begin(); i != v.end(); i++) //Looping via iterator
    {
        cout << *i << " ";
    }
    cout << endl;

    for (auto ele : v) //Looping like python; auto defines data type (automaticlly); ele is used as element in v
    {
        cout << ele << " ";
    }

    //More assignment ways
    //assigning all values same
    vector<int> v2(3, 5);   //vector name (no of values, value)
    vector<int> v3(3);      // 3 values , value = 0
    v3 = v;                 // assigning v to v3
    v2 = vector<int>(2, 3); // making vector v2 a new vector of size 2 and value 3

    swap(v, v2);              // or v.swap(v2);
    sort(v.begin(), v.end()); //sorts
    v.pop_back();             // to remove last element

    //2D vector
    vector<vector<int>> x(5, vector<int>(5, -1)); //making matrix of 5 * 5 with values -1 as default

    v = {1,2,3,4,5,6};

    int a = *max_element(v.begin(), v.end()); //max element returns reference to the maximum element
    cout << a << endl;
    a = *min_element(v.begin(), v.end());     //min element returns reference to the minimum element
    cout << a << endl;

    a = accumulate(v.begin(),v.end(),0);    //gives sum of all elements 
    //syntax: iterator at start , iterator at end , initial value (to add all elements to it)
    cout << a << endl;

    partial_sum(v.begin(),v.end(),v.begin());       // it changes the vector to cummiliative sum vector
    // {1,2,3,4} -> {1,3,6,10}
    for (auto ele:v)
    {
        cout << ele << " ";
    }
}