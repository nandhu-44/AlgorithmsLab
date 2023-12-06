#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int longestSubSequence(const char *s1, const char *s2);

int main()
{
    char s1[100], s2[100];
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    int lcs = longestSubSequence(s1, s2);
    cout << "The length of the longest common subsequence is: " << lcs << endl;
    return 0;
}

int longestSubSequence(const char *s1, const char *s2)
{
    int n1 = strlen(s1), n2 = strlen(s2);
    int b[n1][n2];
    int c[n1 + 1][n2 + 1];

    for (int i = 0; i <= n1; i++)
    {
        c[i][0] = 0;
    }

    for (int j = 0; j <= n2; j++)
    {
        c[0][j] = 0;
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 0; // Diagonal
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1; // Up
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = -1; // Left
            }
        }
    }

    string lcs;
    int i = n1, j = n2;
    while (i > 0 && j > 0)
    {
        if (b[i][j] == 0)
        {
            lcs += s1[i - 1];
            i--;
            j--;
        }
        else if (b[i][j] == 1)
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << "The longest common subsequence is: " << lcs << endl;

    return c[n1][n2];
}
