#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<algorithm>
using namespace std;

vector<int> countSort(vector<int>v)
{
    int max = *max_element(v.begin(),v.end());
    vector<int> count (max+1,0);
    for (auto ele:v)
    {
        count[ele] ++;
    }
    for (int i = 1; i < count.size(); i ++)
    {
        count[i] = count[i] + count[i-1];
    }
    vector<int> res (v.size(),0);
    for (int i = v.size() - 1; i >= 0; i --)
    {
        int loc = --count[v[i]];
        res[loc] = v[i];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v (n);
    for (auto &i : v)
    {
        cin >> i;
    }
    v = countSort(v);
    for (auto ele:v)
    {
        cout << ele << " ";
    }
    cout << endl;
}