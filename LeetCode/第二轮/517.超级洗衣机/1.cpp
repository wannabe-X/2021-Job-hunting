/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-29 17:40:54
 * @LastEditTime: 2021-09-29 18:13:48
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinMoves(vector<int> &machines)
{
    int sum = 0;
    for (int i = 0; i < machines.size(); i++)
        sum += machines[i];

    if (sum % machines.size())
        return -1;

    int avg = sum / machines.size();

    int res = 0;
    sum = 0;
    for (int num : machines)
    {
        num -= avg;
        sum += num;
        res = max(res, max(abs(sum), num));
    }

    return res;
}

int main(void)
{
    vector<int> machines = {4, 0, 4, 0};
    int ans = findMinMoves(machines);
    cout << ans << endl;

    return 0;
}