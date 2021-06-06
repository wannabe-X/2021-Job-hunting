#include <iostream>
#include <vector>

using namespace std;

int getZeroOnes(string &str)
{
    int numofzero = 0;
    for (char c : str)
    {
        if (c == '0')
            numofzero++;
    }
    return numofzero;
}

int findMaxForm(vector<string> &strs, int m, int n)
{
    int len = strs.size();
    vector<vector<vector<int>>> res(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    for (int i = 1; i < len + 1; i++)
    {
        int zeros = getZeroOnes(strs[i - 1]);
        int ones = strs[i - 1].size() - zeros;

        for (int j = 0; j < m + 1; j++)
        {
            for (int k = 0; k < n + 1; k++)
            {
                res[i][j][k] = res[i - 1][j][k];
                if (j >= zeros && k >= ones)
                {
                    res[i][j][k] = max(res[i][j][k], res[i - 1][j - zeros][k - ones] + 1);
                }
            }
        }
    }
    return res[len][m][n];
}

int main()
{
    int numofstrs;
    cin >> numofstrs;
    vector<string> strs(numofstrs);
    int idx = 0;
    while (cin >> strs[idx++] && idx < numofstrs)
        ;
    int m, n;
    cin >> m >> n;
    int ans = findMaxForm(strs, m, n);
    cout << ans << endl;

    return 0;
}