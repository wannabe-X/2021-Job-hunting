// 01背包问题

/*
    f[i][j] 表示只看前i个物品，总体积是j的情况下，总价值最大是多少？
    result = max(f[n][0-v])

    状态转移：
        f[i][j]:
            1.不选第i个物品：f[i][j] = f[i-1][j]
            2.选第i个物品：f[i][j] = f[i-1][j-v[i]]
        f[i][j] = max(1,2)

    初始状态：f[0][0] = 0;

    时间复杂度：O(nv)
    空间：4 * 1000 * 1000 / 1024 /1024 = 4MB
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// const int N = 1010;

// int n, m;
// int f[N][N];
// int v[N], w[N];

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> v[i] >> w[i];
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= m; j++)
//         {
//             f[i][j] = f[i - 1][j];
//             if (j >= v[i])
//             {
//                 f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
//             }
//         }
//     }

//     // int res = 0;
//     // for (int i = 0; i <= m; i++)
//     //     res = max(res, f[n][i]);
//     // cout << res << endl;
    
//     cout << f[n][m] << endl;

//     return 0;
// }

// 优化为一位数组
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1001;

int n, m;
int f[N];
int v[N], w[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
    {
        // 一定要从后往前遍历，保证j-v[i]在本轮没有被修改
        for (int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << endl;

    return 0;
}
