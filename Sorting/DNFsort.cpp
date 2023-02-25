//Based on DNF: Dutch National Flag color : red white blue   i.e. 0,1,2
#include <bits/stdc++.h>
using namespace std;
vector<int> dnfSort(vector<int> v)
{
    int l = 0;
    int m = 0;
    int h = v.size() - 1;
    while (m <= h)
    {
        switch (v[m])
        {
        case 0:
            swap(v[m], v[l]);
            l++;
            m++;
            break;
        case 1:
            m++;
            break;
        case 2:
            swap(v[m], v[h]);
            h--;
            break;
        default:
            break;
        }
    }
    return v;
}
int main()
{

    int n;
    cin>>n;
    vector<int> v (n);
    for (auto &ele : v)
    {
        cin >> ele;
    }
    
    v = dnfSort(v);

    for (auto ele : v)
    {
        cout << ele << " ";
    }
}