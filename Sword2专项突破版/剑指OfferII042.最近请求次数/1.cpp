/*
 * @Description: 剑指 Offer II 042. 最近请求次数
 * @Author: Mr. Lee
 * @Date: 2021-08-25 14:55:13
 * @LastEditTime: 2021-08-25 15:07:39
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class RecentCounter
{
public:
    RecentCounter()
    {
        n = 0;
    }

    int ping(int t)
    {
        q.push(t);
        int tmp1 = 0, tmp2 = q.size();
        while (q.front() < (t - 3000))
        {
            q.pop();
            tmp1++;
        }

        return tmp2 - tmp1;
    }

private:
    int n;
    queue<int> q;
};

int main(int argc, char *argv[])
{
    return 0;
}