/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-10 00:01:49
 * @LastEditTime: 2021-09-10 00:24:16
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int chalkReplacer(vector<int> &chalk, int k)
{
    int sum = 0;
    for (int i = 0; i < chalk.size(); i++)
    {
        sum += chalk[i];
        if (sum > k)
            return i;
    }

    int tk = k % sum;

    for (int i = 0; i < chalk.size(); i++)
    {
        tk -= chalk[i];
        if (tk < 0)
            return i;
    }

    return 0;
}

int main(void)
{
    vector<int> chalk = {3, 4, 1, 2};
    int k = 25;
    int ans = chalkReplacer(chalk, k);
    cout << ans << endl;

    return 0;
}