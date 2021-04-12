#include <iostream>

using namespace std;

int minDistance(string word1, string word2)
{
    int m = word1.size(), n = word2.size();
    int dp[m + 1][m + 1];
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = i;
    for (int j = 0; j < n + 1; j++)
        dp[0][j] = j;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (word1.at(i - 1) == word2.at(j - 1))
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(
                    min(1 + dp[i][j - 1], 1 + dp[i - 1][j]), 1 + dp[i - 1][j - 1]);
        }
    }
    return dp[m][n];
}

int main(void)
{
    string word1 = "dinitrophenylhydrazine";
    string word2 = "benzalphenylhydrazone";
    int mD = minDistance(word1, word2);
    cout << mD << endl;
}