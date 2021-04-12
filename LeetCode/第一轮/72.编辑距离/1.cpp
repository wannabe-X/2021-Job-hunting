#include <iostream>

using namespace std;

int dp(string word1, string word2, int i, int j)
{
    if (i == -1)
        return j + 1;
    if (j == -1)
        return i + 1;

    if (word1[i] == word2[j])
        return dp(word1, word2, i - 1, j - 1);
    else
    {
        return min(
            min(1 + dp(word1, word2, i, j - 1),
                1 + dp(word1, word2, i - 1, j)),
            1 + dp(word1, word2, i - 1, j - 1));
    }
}

int minDistance(string word1, string word2)
{

    return dp(word1, word2, word1.size() - 1, word2.size() - 1);
}

int main(void)
{
    string word1 = "dinitrophenylhydrazine";
    string word2 = "benzalphenylhydrazone";
    int mD = minDistance(word1, word2);
    cout << mD << endl;
}