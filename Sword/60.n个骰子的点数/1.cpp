#include <iostream>
#include <vector>

using namespace std;

// f(n,x) = sum(f(n-1,x-i)*1/6.0),i=1,2,3,4,5,6
// 可以看出 上一轮的每一个f[j]只对下一轮的f[j+k]有作用

vector<double> dicesProbability(int n)
{
    vector<double> f(6, 1.0 / 6);
    for (int i = 2; i <= n; i++)
    {
        vector<double> temp(5 * i + 1);
        for (int j = 0; j < f.size(); j++)
        {
            // 由于新增骰子的点数只可能为 1 至 6 ，
            // 因此概率 f(n - 1, x) 仅与 f(n, x + 1) , f(n, x + 2), ... , f(n, x + 6) 相关。
            // 因而，遍历 f(n - 1)中各点数和的概率，并将其相加至f(n)中所有相关项，即可完成f(n - 1)至f(n)的递推。
            for (int k = 0; k < 6; k++)
                temp[j + k] += (f[j] / 6.0);
        }
        f = temp;
    }
    return f;
}

int main(void)
{
    int n = 2;
    vector<double> ans = dicesProbability(n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}