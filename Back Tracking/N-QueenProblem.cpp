#include <iostream>
using namespace std;

bool isSafe(int **arr, int n, int i, int j) //to check if a position is safe or not
{
    if (i >= n || j >= n)
    {
        return false;
    }
    for (int x = i; x >= 0; x--)
    {
        if (arr[x][j] == 1)
        {
            return false;
        }
    }
    int row = i, col = j;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        col--;
        row--;
    }
    row = i;
    col = j;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        col++;
        row--;
    }
    return true;
}

bool NQueenProblem(int n, int **arr, int row = 0)
{
    if (row >= n)
    {
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, n, row, col))
        {
            arr[row][col] = 1;
            if (NQueenProblem(n, arr, row + 1))
            {
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter chess board size: ";
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++) //Initializing with zero
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    NQueenProblem(n, arr);
    for (int i = 0; i < n; i++) //Output
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << "\n";
    }
}