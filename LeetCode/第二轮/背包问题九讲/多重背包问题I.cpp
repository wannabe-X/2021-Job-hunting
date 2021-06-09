/*
    f[i] 表示总体积为i的情况下，最大价值是多少？
    for(int i=0;i<n;i++){
        for(int j=m;j>v[i];j--){
            // 对s[i] 进行枚举
            f[j] = max(f[j],f[j-v[i]]+w[i],f[j-2*v[i]]+2*w[i],...)
        }
    }
*/

// 优化为一位数组
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 101;

int n, m;
int f[N];
int v[N], w[N], s[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= m; j++)
        {
            if ((j - v[i]) / v[i] <= s[i])
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            // for (int k = 1; k <= s[i] && k * v[i] <= j; k++)
            // {
            //     f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
            // }
        }
    }

    cout << f[m] << endl;

    return 0;
}