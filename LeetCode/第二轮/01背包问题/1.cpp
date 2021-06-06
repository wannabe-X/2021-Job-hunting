#include <iostream>
#include <vector>

using namespace std;

int maxValue(vector<vector<int>> &v_w, int p)
{
    int m = v_w.size();
    // res[i][j]的含义，表示要有前i件物品，且背包容量为j时，能装下礼物的最大值
    vector<vector<int>> res(m + 1, vector<int>(p + 1, 0));
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < p + 1; j++)
        {
            if (j < v_w[i - 1][1])
                // 装不进去
                res[i][j] = res[i - 1][j];
            else if (j >= v_w[i - 1][1])
                // 能装进去，装和不装取最大值
                // res[i - 1][j] 不装，当前背包容量能装下的礼物价值
                // res[i - 1][j - v_w[i - 1][1]]，不装，当前背包容量减去要装的物品的重量之后，当前背包能能装下的礼物价值
                // res[i - 1][j - v_w[i - 1][1]] + v_w[i - 1][0] 装，当前背包能能装下的礼物价值
                res[i][j] = max(res[i - 1][j], res[i - 1][j - v_w[i - 1][1]] + v_w[i - 1][0]);
        }
    }

    return res[m][p];
}

int main()
{
    int numofgifts; // 礼物的件数
    cin >> numofgifts;
    vector<vector<int>> value_weight(numofgifts, vector<int>(2, 0));
    int idx = 0;
    while (idx < numofgifts)
    {
        cin >> value_weight[idx][0] >> value_weight[idx][1];
        idx++;
    }

    int package = 0;
    cin >> package; // 背包的容量
    int ans = maxValue(value_weight, package);
    cout << ans << endl;
    
    return 0;
}