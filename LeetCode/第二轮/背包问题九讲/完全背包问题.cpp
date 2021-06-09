/*
    f[i] 表示总体积为i的情况下，最大价值是多少
    result = max(f[0],f[1],...,f[m]);

    for(int i=0;i<n;i++){
        for(int j=v[i];j,=m;j++){
            f[j] = max(f[j],f[j-v[i]]+w[i]);
        }
    }

*/

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
        // 一定要从前往后遍历，保证j-v[i]在本轮已经被修改
        for (int j = v[i]; j <= m; j++)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << endl;

    return 0;
}