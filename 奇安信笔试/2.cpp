/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-23 14:50:30
 * @LastEditTime: 2021-08-23 18:35:49
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int gys(int a, int b)
{
    while (b)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

vector<int> getFraction(float a)
{
    float diff = 1.0;
    vector<int> res;

    for (int i = 1; i < 200; i++)
    {
        for (int j = i + 1; j < 200; j++)
        {
            float tmp = ((i + 0.0) / j);
            if (abs(tmp - a) <= diff)
            {
                diff = abs(tmp - a);
                res = {i, j};
            }
        }
    }

    int n = res[0], m = res[1];
    res = {res[0] / gys(n, m), res[1] / gys(n, m)};

    return res;
}

int main()
{
    float num = 0.333333333;
    // cin >> num;
    vector<int> ans = getFraction(num);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}