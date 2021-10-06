/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-29 09:59:32
 * @LastEditTime: 2021-09-29 11:01:47
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> func(int N, int A, int B, int C)
{
    int x, y, z;
    vector<int> res(3, 0);
    int temp = 0;
    for (int i = N / A; i >= 0; i--)
    {
        for (int j = N / B; j >= 0; j--)
        {
            int target = N - A * i - B * j;
            int tmpC = target > 0 ? target / C : 0;
            if (A * i + B * j + tmpC * C == N)
            {
                if (i + j + tmpC > temp)
                {
                    res[0] = i;
                    res[1] = j;
                    res[2] = tmpC;

                    temp = i + j + tmpC;
                }
            }
        }
    }

    if (res[0] + res[1] + res[2] > 0)
        return res;

    return {};
}

int main(void)
{
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> ans = func(N, A, B, C);
    if (ans.empty())
        cout << -1;
    else
        cout << ans[0] << " " << ans[1] << " " << ans[2];

    return 0;
}