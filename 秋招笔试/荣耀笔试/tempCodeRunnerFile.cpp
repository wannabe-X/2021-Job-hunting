/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-28 18:02:23
 * @LastEditTime: 2021-08-28 19:28:39
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int timeMin(int *time, int n)
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

int timeMax(int *time, int n)
{
    int max = time[0];
    for (int i = 0; i < n; i++)
    {
        if (max < time[i])
            max = time[i];
    }

    return max;
}

int processingTime(int m, int n, int *time)
{
    int count = n;
    if (count == 0)
    {
        return 0;
    }

    if (n > m)
    {
        vector<vector<int>> fg(m, vector<int>(2, 0));
        int resultTime = 0;
        int end = 0;
        while (end - 1)
        {
            for (int i = 0; i < m && count > 0; i++)
            {
                if (fg[i][0] == 0)
                {
                    fg[i][0] = 1;
                    fg[i][1] = timeMin(time, n);
                    count--;
                }
            }

            int fgk = 0;
            for (int i = 0; i < m; i++)
            {
                if (fg[i][1] == 0)
                    fgk++;
            }

            if (fgk == m)
            {
                end = 1;
                continue;
            }

            for (int i = 0; i < m; i++)
            {
                if (fg[i][1])
                    fg[i][1]--;

                if (fg[i][1] == 0)
                {
                    fg[i][0] = 0;
                }
            }

            resultTime++;
        }

        return resultTime;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    int time[100];
    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }

    int ans = processingTime(m, n, time);

    return 0;
}
