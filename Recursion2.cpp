#include<iostream>
using namespace std;
int mx = INT_MIN;
void PermutationStr (string s, string ans = "")
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i ++)
    {
        string temp = s;
        temp.erase(temp.begin() + i);
        PermutationStr (temp, ans + s[i]); 
    }
}
int NoOfWays (int start, int end)
{
    if (start == end)
    return 1;
    if (start > end)
    return 0;
    int count = 0;
    for (int i = 1; i <= 6; i ++)
    {
        count += NoOfWays (start + i, end);
    }
    return count;
}
int NoOfChocolate (int moneyInHand, int cost, int wrapperPerChoc, int WrapperInPoc = 0)
{
    if (moneyInHand < cost && WrapperInPoc < wrapperPerChoc)
    return 0;
    int count = 0;
    int choclatesBought = (moneyInHand / cost) + (WrapperInPoc / wrapperPerChoc);
    count += choclatesBought;
    count += NoOfChocolate (moneyInHand % cost, cost, wrapperPerChoc, (WrapperInPoc % wrapperPerChoc) + choclatesBought);
    return count;
}
int NoOfWaysInMaze (int row, int coloumn)       //start at (1,1)    go to (row,coloumn)
{
    if (row == 1 && coloumn == 1)
    {
        return 1;
    }
    if (row < 1 || coloumn < 1)
    {
        return 0;
    }
    int count = 0;
    count += (NoOfWaysInMaze(row-1, coloumn) + NoOfWaysInMaze(row, coloumn - 1));
    return count;
}
int Tiling (int n)
{
    if (n == 1 || n == 0)       // we use 1,0 bcoz we have to make different combinations
    return n;
    return Tiling(n-1) + Tiling(n-2);
}
int FreindsPairing (int n)
{
    if (n == 1 || n == 2)       //we use 1,2 bcoz we have to make diffrent permutations
    return n;
    return FreindsPairing(n-1) + FreindsPairing(n-2) * (n-1) ;      //multiply by n-1 bcoz we can pair with any of n-1 people left
}
void KnapSack (int v[], int w[], int n, int W, string ans = "", int index = 0)
{
    if (n == index)
    {
        int totalW = 0, totalV = 0;
        for (int i = 0; i < ans.size(); i ++)
        {
            totalW += w[ans[i] - '0'];
            totalV += v[ans[i] - '0'];
        }
        if (totalW <= W)
        {
            mx = max(mx,totalV); 
        }
        return;
    }
    KnapSack(v, w, n, W, ans, index+1);
    KnapSack(v, w, n, W, ans + to_string(index), index+1);
    
    return;
}
int main()
{
    // PermutationStr ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    // cout << NoOfWays (0, 2) << endl;
    // cout << NoOfChocolate (20,3,5) << endl;
    // cout << NoOfWaysInMaze (3,3) << endl;
    // cout << Tiling (4) << endl;
    // cout << FreindsPairing(4) << endl;
    int w[] = {1, 1, 1};
    int v[] = {10, 20, 30};
    KnapSack(v,w,3,2);
    cout << mx << endl;
}