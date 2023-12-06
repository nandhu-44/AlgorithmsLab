#include <iostream>
#include <algorithm>
using namespace std;

void changeMakingProblem(int[], int, int);
void printUsedCoins(int[], int, int, int[][100]);

int main()
{
    int n, amount;
    cout << "Enter the number of coins: ";
    cin >> n;
    int coins[n] = {0};
    cout << "Enter the coins: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << "Enter the amount: ";
    cin >> amount;
    changeMakingProblem(coins, n, amount);
    return 0;
}

void changeMakingProblem(int coins[], int n, int amount)
{
    int F[n + 1][amount + 1] = {0};
    int usedCoins[n + 1][100] = {0};

    for (int i = 0; i <= n; i++)
    {
        F[i][0] = 0;
    }
    for (int i = 0; i <= amount; i++)
    {
        F[0][i] = INT16_MAX * 100;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (j < coins[i - 1])
            {
                F[i][j] = F[i - 1][j];
                usedCoins[i][j] = usedCoins[i - 1][j];
            }
            else
            {
                int withCurrentCoin = 1 + F[i][j - coins[i - 1]];
                int withoutCurrentCoin = F[i - 1][j];

                if (withCurrentCoin < withoutCurrentCoin)
                {
                    F[i][j] = withCurrentCoin;
                    usedCoins[i][j] = i;
                }
                else
                {
                    F[i][j] = withoutCurrentCoin;
                    usedCoins[i][j] = usedCoins[i - 1][j];
                }
            }
        }
    }

    cout << "Min coins required: " << F[n][amount] << endl;
    printUsedCoins(coins, n, amount, usedCoins);
}

void printUsedCoins(int coins[], int n, int amount, int usedCoins[][100])
{
    cout << "Coins used: ";
    while (amount > 0)
    {
        int coinIndex = usedCoins[n][amount];
        cout << coins[coinIndex - 1] << " ";
        amount -= coins[coinIndex - 1];
    }
    cout << endl;
}
