#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> ans;
void permuteBySTL(vector<int> a)
{
    sort(a.begin(), a.end()); //sorting is neccessary because next_permutation gives greater values only
    do
    {
        ans.push_back(a);
    } while (next_permutation(a.begin(), a.end()));
}
void permute(vector<int> a, int id = 0)
{
    if (id == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = id; i < a.size(); i++)
    {
        if (i != id && a[i] == a[id]) continue;   //condition is to avoid duplicates
        swap(a[i], a[id]);
        permute(a, id + 1);
        swap(a[i], a[id]);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    permute(a);
    for (auto vec : ans)
    {
        for (auto ele : vec)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}