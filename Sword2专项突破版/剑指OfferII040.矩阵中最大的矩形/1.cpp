/*
 * @Description: 剑指 Offer II 040. 矩阵中最大的矩形
 * @Author: Mr. Lee
 * @Date: 2021-09-07 11:19:37
 * @LastEditTime: 2021-09-07 15:18:48
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

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

int maximalRectangle(vector<string> &matrix)
{
    if (matrix.empty())
        return 0;

    vector<int> heights(matrix[0].size(), 0);
    int maxArea = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == '0')
                heights[j] = 0;
            else
                heights[j] += matrix[i][j] - '0';
        }

        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main(void)
{
    vector<string> matrix = {"10100", "10111", "11111", "10010"};
    int ans = maximalRectangle(matrix);
    cout << ans << endl;

    return 0;
}