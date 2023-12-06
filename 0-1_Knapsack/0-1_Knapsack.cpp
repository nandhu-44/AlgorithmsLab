#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int, int *, int *, int);

int main()
{
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    cout << "Enter the weights of the items: ";
    int *weights = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    cout << "Enter the profits of the items: ";
    int *profits = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> profits[i];
    }
    cout << "The maximum profit is: " << knapsack(W, weights, profits, n) << endl;
    delete[] weights;
    delete[] profits;
    return 0;
}

int knapsack(int W, int *weights, int *profits, int n)
{
    int **c = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        c[i] = new int[W + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        c[i][0] = 0;
    }

    for (int j = 0; j <= W; j++)
    {
        c[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int weight = weights[i - 1];
            if (weight <= j)
            {
                c[i][j] = std::max(c[i - 1][j], profits[i - 1] + c[i - 1][j - weight]);
            }
            else
            {
                c[i][j] = c[i - 1][j];
            }
        }
    }

    int result = c[n][W];

    for (int i = 0; i <= n; i++)
    {
        delete[] c[i];
    }
    return result;
}
