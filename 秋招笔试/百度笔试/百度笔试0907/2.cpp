/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-07 18:47:52
 * @LastEditTime: 2021-09-07 20:26:50
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int x, int y)
{
    int t;
    while (y)
    {
        t = x;
        x = y;
        y = t % y;
    }

    return x;
}

int func(int N)
{
    vector<int> r;
    for (int i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            r.push_back(i);

            if (i * i != N)
            {
                r.push_back(N / i);
            }
        }
    }

    sort(r.begin(), r.end());

    int res = 0;

    int i = 0, j = r.size() - 1;
    while (i < j)
    {
        if (gcd(r[j--], r[i++]) == 1)
            res += 1;
    }

    return res;
}

int main(void)
{
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        int ans = func(N);
        cout << ans << endl;
    }

    return 0;
}