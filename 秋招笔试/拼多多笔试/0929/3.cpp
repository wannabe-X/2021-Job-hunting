/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-29 09:59:43
 * @LastEditTime: 2021-09-29 12:40:03
 * @LastEditors: Mr. Lee
 */

#include <iostream>

using namespace std;
const int N = 1005;
int n, z[2 * N + 5], y[2 * N + 5], ansj, anso, s[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> s[i][j];
            z[i - j + n] += s[i][j];
            y[i + j - 1] += s[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i + j) & 1)
            {
                ansj = max(ansj, z[i - j + n] + y[i + j - 1] - s[i][j]);
            }
            else
            {
                anso = max(anso, z[i - j + n] + y[i + j - 1] - s[i][j]);
            }
        }
    }
    cout << ansj + anso;
    return 0;
}