#include <iostream>
using namespace std;

bool isSafe(int **arr, int n, int x, int y)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}
bool isSafe(int **arr, int r, int c, int i, int j)
{
    if (j < c && i < r && arr[i][j] == 1)
    {
        return true;
    }
    return false;
}

bool RatInSquareMaze(int **arr, int n, int **solArr, int x = 0, int y = 0)
{
    if ((x == (n - 1)) && (y == (n - 1)))
    {
        solArr[x][y] = 1;
        return true;
    }
    if (isSafe(arr, n, x, y))
    {
        solArr[x][y] = 1;
        if (RatInSquareMaze(arr, n, solArr, x + 1, y))
        {
            return true;
        }
        if (RatInSquareMaze(arr, n, solArr, x, y + 1))
        {
            return true;
        }
        solArr[x][y] = 0;
        return false;
    }
    return false;
}
bool RatInRectangleMaze(int **arr, int r, int c, int **solArr, int i = 0, int j = 0)
{
    if (i == r-1 && j == c-1)
    {
        solArr[i][j] = 1;
        return true;
    }
    if (isSafe(arr,r,c,i,j))
    {
        solArr[i][j] = 1;
        if (RatInRectangleMaze(arr,r,c,solArr,i+1,j))
        {
            return true;
        }
        if (RatInRectangleMaze(arr,r,c,solArr,i,j+1))
        {
            return true;
        }
        solArr[i][j] = 0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            solArr[i][j] = 0;
        }
    }
    cout << "*******************\n";
    RatInSquareMaze(arr, n, solArr);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solArr[i][j] << " ";
        }
        cout << endl;
    }

    int r,c;
    cin >> r >> c;
    int **a = new int*[r];
    int **b = new int*[r];
    for (int i = 0; i < r; i ++)
    {
        a[i] = new int[c];
        b[i] = new int[c];
        for (int j = 0; j < c; j ++)
        {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }

    RatInRectangleMaze (a,r,c,b);
    cout << "*******************************\n";

    for (int i = 0; i < r; i ++)
    {
        for (int j = 0; j < c; j ++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}