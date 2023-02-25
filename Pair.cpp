#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
int main()
{
    pair<int, int> p;
    p.first = 1;
    p.second = 3;

    p = make_pair(2, 3);                       //Updating values
    pair<float, char> p = make_pair(2.0, 'a'); //changing type of p to float,char

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    vector<pair<int, int>> help;
    for (int i = 0; i < v.size(); i++) //making a new vector of pairs of type (value, index)
    {
        help.push_back(make_pair(v[i], i));
    }
    sort(help.begin(), help.end(), compare); //sorting it on basis of compare function
    for (int i = 0; i < help.size(); i++)
    {
        v[help[i].second] = i;
    }
    for (auto ele : v)
    {
        cout << ele << " ";
    }
}