/*
 * @Description: 1518. 换酒问题
 * @Author: Mr. Lee
 * @Date: 2021-12-17 00:06:24
 * @LastEditTime: 2021-12-17 00:25:37
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numWaterBottles(int numBottles, int numExchange)
{
    int res = numBottles;
    while (numBottles >= numExchange)
    {
        res += numBottles / numExchange;
        numBottles = numBottles / numExchange + numBottles % numExchange;
    }

    return res;
}

int main(int argc, char *argv[])
{
    int numBottles = 9, numExchange = 3;
    int ans = numWaterBottles(numBottles, numExchange);
    cout << ans << endl;

    return 0;
}