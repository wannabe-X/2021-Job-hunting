/*
 * @Description: leetcode 279. 完全平方数。BFS
 * @Author: Mr. Lee
 * @Date: 2021-06-11 11:16:17
 * @LastEditTime: 2021-06-11 11:23:23
 * @LastEditors: Mr. Lee
 */

/*
    BFS的做法，比较巧妙。
    每一次是原数字减去了一个平方数，直到出现第一个0，此时走过的层数就是最小数量，即为答案
*/

#include <iostream>
#include <math.h>
#include <vector>
#include<queue>
#include<set>

using namespace std;

int numSquares(int n)
{
    vector<int> sqrtnum;
    for (int i = 0; i < sqrt(n) + 1; i++)
    {
        sqrtnum.push_back(i * i);
    }

    set<int> visited;
    queue<int> q;
    q.push(n);
    visited.insert(n);
    int level = 0;
    
    while (!q.empty())
    {
        int len = q.size();
        level++; //level意味着此时分开几个数的组合，当找到第一个符合的组合即return
        for (int i = 0; i < len; i++)
        {
            int node = q.front();
            q.pop();
            for (int j = 1; j * j <= node; j++)
            {
                int temp = node - j * j;
                if (temp == 0)
                    return level;
                if (visited.find(temp) == visited.end())
                    q.push(temp);
                visited.insert(temp);
            }
        }
    }
    
    return level;
}

int main()
{
    // 测试用例
    // int n = 13;
    // int ans = numSquares(n);

    int n;
    cin >> n;
    int ans = numSquares(n);

    cout << ans << endl;
    return 0;
}