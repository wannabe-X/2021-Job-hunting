#include <iostream>
#include <vector>

using namespace std;

vector<double> dicesProbability(int n)
{
    vector<double> f(6, 1.0 / 6);
    for (int i = 2; i <= n; i++)
    {
        vector<double> temp(5 * i + 1);
        for (int j = 0; j < f.size(); j++)
        {
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