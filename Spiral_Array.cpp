#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter row number follwed by coloumn number: ";
    cin >> n >> m;
    int a[n][m];
    cout << "Enter array elements row by row : ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    cout << "Your array: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    cout << "Your array in spiral form: \n";
    int topRow = 0, leftCol = 0, rightCol = m - 1, bottomRow = n - 1;
    while (topRow <= bottomRow && leftCol <= rightCol)
    {
        if (topRow <= bottomRow && leftCol <= rightCol)
        {
            for (int i = leftCol; i <= rightCol; i++)
                cout << a[topRow][i] << " ";
            topRow++;
            cout << endl;
        }

        if (topRow <= bottomRow && leftCol <= rightCol)
        {
            for (int i = topRow; i <= bottomRow; i++)
                cout << a[i][rightCol] << " ";
            rightCol--;
            cout << endl;
        }

        if (topRow <= bottomRow && leftCol <= rightCol)
        {
            for (int i = rightCol; i >= leftCol; i--)
                cout << a[bottomRow][i] << " ";
            bottomRow--;
            cout << endl;
        }

        if (topRow <= bottomRow && leftCol <= rightCol)
        {
            for (int i = bottomRow; i >= topRow; i--)
                cout << a[i][leftCol] << " ";
            leftCol++;
            cout << endl;
        }
    }
}