/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-28 18:02:23
 * @LastEditTime: 2021-08-28 19:40:01
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int minTime(vector<int> &time, int n)
{
    int min = time[0], k = 0;
    for (int i = 0; i < n; i++)
    {
        if (min > time[i])
        {
            k = i;
            min = time[i];
        }
    }

    time[k] = 100;

    return min;
}

int process(int m, int n, vector<int> &time)
{
    if (!n)
        return 0;

    int count = n;

    if (n > m)
    {
        vector<vector<int>> fg(m, vector<int>(2, 0));
        int res = 0;
        int end = 0;
        while (end != 1)
        {
            for (int i = 0; i < m && count > 0; i++)
            {
                if (fg[i][0] == 0)
                {
                    fg[i][0] = 1;
                    fg[i][1] = minTime(time, n);
                    count--;
                }
            }

            int tmp = 0;
            for (int i = 0; i < m; i++)
            {
                if (fg[i][1] == 0)
                    tmp++;
            }

            if (tmp == m)
            {
                end = 1;
                continue;
            }

            for (int i = 0; i < m; i++)
            {
                if (fg[i][1])
                    fg[i][1]--;

                if (fg[i][1] == 0)
                    fg[i][0] = 0;
            }

            res++;
        }

        return res;
    }

    // 若以上没有返回，则直接返回最大时间
    int maxt = time[0];
    for (int i = 0; i < n; i++)
    {
        maxt = max(maxt, time[i]);
    }

    return maxt;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> time(n);

    for (int i = 0; i < n; i++)
        cin >> time[i];

    int ans = process(m, n, time);
    cout << ans;

    return 0;
}
