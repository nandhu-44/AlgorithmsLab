#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void printMatrix(int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void backTrack(int **F, int n, int m)
{
    int i = n - 1, j = m - 1;
    while (i != 0 || j != 0)
    {
        cout << "(" << i + 1 << "," << j + 1 << ") -> ";
        if (i == 0)
        {
            j--;
        }
        else if (j == 0)
        {
            i--;
        }
        else if (F[i - 1][j] > F[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << "(1,1)" << endl;
}

int coinCollection(int **C, int n, int m)
{
    int **F = new int *[n];
    for (int i = 0; i < n; i++)
    {
        F[i] = new int[m];
    }
    F[0][0] = C[0][0];

    for (int i = 1; i < m; i++)
    {
        F[0][i] = F[0][i - 1] + C[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        F[i][0] = F[i - 1][0] + C[i][0];
        for (int j = 1; j < m; j++)
        {
            F[i][j] = max(F[i - 1][j], F[i][j - 1]) + C[i][j];
        }
    }

    cout << "Matrix F: " << endl;
    printMatrix(F, n, m);

    cout << "Path: ";
    backTrack(F, n, m);
    return F[n - 1][m - 1];
}

int main()
{
    int n, m;
    int **matrix;
    cout << "Enter the size of the matrix: ";
    cin >> n >> m;
    matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter row " << i + 1 << " : ";
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int maxCoins = coinCollection(matrix, n, m);
    cout << "Maximum coins collected: " << maxCoins << endl;
    return 0;
}
