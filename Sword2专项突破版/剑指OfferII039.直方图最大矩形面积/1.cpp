/*
 * @Description: 剑指 Offer II 039. 直方图最大矩形面积
 * @Author: Mr. Lee
 * @Date: 2021-08-27 23:53:29
 * @LastEditTime: 2021-08-28 00:38:01
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 单调栈 递增栈
int largestRectangleArea(vector<int> &heights)
{
    stack<int> s;
    s.push(-1);
    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        while (s.top() != -1 && heights[s.top()] >= heights[i])
        {
            int height = heights[s.top()];
            s.pop();
            int width = i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }

        s.push(i);
    }

    while (s.top() != -1)
    {
        int height = heights[s.top()];
        s.pop();
        int width = heights.size() - s.top() - 1;
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}

int main(int argc, char *argv[])
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int ans = largestRectangleArea(heights);
    cout << ans << endl;

    return 0;
}