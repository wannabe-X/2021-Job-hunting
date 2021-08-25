/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-25 14:37:18
 * @LastEditTime: 2021-08-25 14:50:04
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class MovingAverage
{
public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        this->size = size;
    }

    double next(int val)
    {
        if (q.size() <= this->size)
        {
            q.push(val);
        }
        else
        {
            q.pop();
            q.push(val);
        }

        // 计算平均值
        double avg = 0.0;
        int len = q.size();

        while (len-- > 0)
        {
            int tmp = q.front();
            avg += tmp;
            q.pop();
            q.push(tmp);
        }

        return ((avg + 0.0) / q.size());
    }

private:
    queue<int> q;
    int size;
};

int main(int argc, char *argv[])
{
    return 0;
}