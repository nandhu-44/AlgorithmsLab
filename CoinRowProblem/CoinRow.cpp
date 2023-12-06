#include <iostream>
#include <algorithm>
using namespace std;

void solveCoinRowProblem(int[], int);
void backTrack(int[], int, int[]);

int main()
{
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;
    int coins[n] = {0};
    cout << "Enter the coins: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    solveCoinRowProblem(coins, n);
    return 0;
}

void solveCoinRowProblem(int coins[], int n)
{
    int F[n + 1] = {0};
    F[0] = 0;
    F[1] = coins[0];
    for (int i = 2; i <= n; i++)
    {
        F[i] = max(coins[i - 1] + F[i - 2], F[i - 1]);
    }
    cout << "Max amount : " << F[n] << endl;
    backTrack(coins, n, F);
}

void backTrack(int coins[], int n, int F[])
{
    int i = n;
    cout << "Coins selected are : [";
    while (i >= 1)
    {
        if (F[i] == F[i - 1])
        {
            i--;
        }
        else
        {
            cout << coins[i - 1];
            if (i > 1)
                cout << ", ";
            i -= 2;
        }
    }
    cout << "]" << endl;
}
