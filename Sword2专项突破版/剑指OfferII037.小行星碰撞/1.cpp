/*
 * @Description: 剑指 Offer II 037. 小行星碰撞
 * @Author: Mr. Lee
 * @Date: 2021-08-26 10:46:35
 * @LastEditTime: 2021-08-26 10:48:36
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    
}

int main(int argc, char *argv[])
{
    vector<int> asteroids = {10, 2, -5};
    vector<int> ans = asteroidCollision(asteroids);
    for (auto &x : ans)
    {
        cout << x << " ";
    }

    return 0;
}