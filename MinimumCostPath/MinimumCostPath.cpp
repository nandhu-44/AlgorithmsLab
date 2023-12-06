#include <iostream>
using namespace std;

int minCostPath(int **, int, int);
int min(int, int, int);

int main()
{
    int m, n;
    cout << "Enter the matrix dimensions : ";
    cin >> m >> n;
    int **c = new int *[m];
    for (int i = 0; i < m; ++i)
    {
        c[i] = new int[n];
    }

    cout << "Enter the matrix : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }

    cout << "Min Cost : " << minCostPath(c, m, n) << endl;

    for (int i = 0; i < m; ++i)
    {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}

int minCostPath(int **c, int m, int n)
{
    int **F = new int *[m];
    for (int i = 0; i < m; i++)
    {
        F[i] = new int[n];
    }

    F[0][0] = c[0][0];

    for (int i = 1; i < n; i++)
    {
        F[0][i] = F[0][i - 1] + c[0][i];
    }

    for (int j = 1; j < m; j++)
    {
        F[j][0] = F[j - 1][0] + c[j][0];
        for (int i = 1; i < n; i++)
        {
            F[j][i] = min(F[j - 1][i], F[j][i - 1], F[j - 1][i - 1]) + c[j][i];
        }
    }

    return F[m - 1][n - 1];
}

int min(int a, int b, int c)
{
    return (a < b && a < c) ? a : ((b < c) ? b : c);
}
