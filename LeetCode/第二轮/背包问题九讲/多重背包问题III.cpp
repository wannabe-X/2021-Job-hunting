/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-06-09 17:42:18
 * @LastEditTime: 2021-06-09 17:50:02
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20001;

int n, m;
int f[N], g[N], q[N];

int main()
{
    cin >> n >> m;
    int c, w, s;

    for (int i = 0; i < n; i++)
    {
        cin >> c >> w >> s;
        memcpy(g, f, sizeof(f));
        for (int j = 0; j < c; j++)
        {
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k += c)
            {
                f[k] = g[k];
                if (hh <= tt && k - s * c > q[hh])
                {
                    hh++;
                }
                if (hh <= tt)
                    f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / c * w);
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / c * w <= g[k] - (k - j) / c * w)
                    tt--;
                q[++tt] = k;
            }
        }
    }

    cout << f[m] << endl;

    return 0;
}
