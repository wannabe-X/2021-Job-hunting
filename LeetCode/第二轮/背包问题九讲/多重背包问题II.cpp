/*
    多重背包的二进制优化方法。
    比如：商品的件数10，可以拆成 1 2 4 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2001;

int n, m;
int f[N];

struct Good
{
    int v, w;
};

int main()
{
    vector<Good> goods;
    cin >> n >> m;
    int v, w, s;
    for (int i = 0; i < n; i++)
    {
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k *= 2)
        {
            s -= k;
            goods.push_back({v * k, w * k});
        }
        if (s > 0)
        {
            goods.push_back({v * s, w * s});
        }
    }

    for (auto good : goods)
    {
        for (int j = m; j >= good.v; j--)
            f[j] = max(f[j], f[j - good.v] + good.w);
    }

    cout << f[m] << endl;
    
    return 0;
}