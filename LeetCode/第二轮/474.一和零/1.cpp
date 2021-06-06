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
    /*
        res[i][j][k]的含义是在前i个字符串中，使用j个0和k个1的情况下最多可以得到的字符串数量。
        假设数组 str 的长度为 len，则最终答案为 res[len][m][n]。

        该题可以类比到01背包问题。
        j可以当做装0的背包的容量
        1可以当做装1的背包的容量
    */
    vector<vector<vector<int>>> res(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    for (int i = 1; i < len + 1; i++)
    {
        int zeros = getZeroOnes(strs[i - 1]);
        int ones = strs[i - 1].size() - zeros;

        for (int j = 0; j < m + 1; j++)
        {
            for (int k = 0; k < n + 1; k++)
            {
                if (j < zeros || k < ones)
                { 
                    // 背包装不下
                    res[i][j][k] = res[i - 1][j][k];
                }
                else if (j >= zeros && k >= ones)
                {
                    // 背包可以装下，考虑是否需要装下当前字符串
                    res[i][j][k] = max(res[i - 1][j][k], res[i - 1][j - zeros][k - ones] + 1);
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