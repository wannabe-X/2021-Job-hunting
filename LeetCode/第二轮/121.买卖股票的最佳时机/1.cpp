/*
 * @Description: 121. 买卖股票的最佳时机
 * @Author: Mr. Lee
 * @Date: 2021-08-27 18:35:19
 * @LastEditTime: 2021-08-27 19:29:51
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/* 
动态规划法：
    动态规划 每一次都计算截止到当前的最低股价(取min) 
    然后利润（当前的价格减去最低股价）最大化（取max） 
*/
// int maxProfit(vector<int> &prices)
// {
//     int res = 0, minPrice = INT_MAX;
//     for (int price : prices)
//     {
//         res = max(res, price - minPrice);
//         minPrice = min(minPrice, price);
//     }

//     return res;
// }

// 单调栈 单调递减栈
// 保持栈顶是当前最小元素，如果利润最大则更新
int maxProfit(vector<int> &prices)
{
    stack<int> s;
    int res = 0;

    for (auto &price : prices)
    {
        // 若当前栈顶元素大于price，则移除，永远保证当前栈顶元素最小
        while (!s.empty() && s.top() >= price)
            s.pop();
        
        // 判断是否需要往栈中添加元素
        if (s.empty())
            s.push(price);

        // 更新结果
        res = max(res, price - s.top());
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int ans = maxProfit(prices);
    cout << ans << endl;

    return 0;
}
