/*
 * @Description: 滑动窗口的最大值。采用单调栈
 * @Author: Mr. Lee
 * @Date: 2021-06-28 23:07:35
 * @LastEditTime: 2021-06-29 14:55:14
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void pushstack(stack<int> &win, int num)
{
    while ((!win.empty()) && (num > win.top()))
    {
        win.pop();
    }

    if (win.empty() || num >= win.top())
        win.push(num);
}

vector<int> maxInWindows(const vector<int> &num, unsigned int size)
{
    if (size > num.size())
        return {};

    stack<int> win;
    vector<int> res;
    int i = 0;

    while (i < num.size())
    {
        if (i < size - 1)
        {
            pushstack(win, num[i]);
        }
        else
        {
            pushstack(win, num[i]);
            res.push_back(win.top());
            int winleft = i - size + 1;
            if (num[winleft] == win.top())
            {
                win.pop();
                for (int m = winleft + 1; m <= i; pushstack(win, num[m]), m++)
                    ;
            }
        }

        i++;
    }

    return res;
}

int main()
{
    // 测试用例
    // vector<int> num = {2,3,4,2,6,2,5,1};
    // unsigned int size = 3;

    //
    int n, idx = 0;
    unsigned int size;
    cin >> n >> size;
    vector<int> num(n);
    while (idx < n && cin >> num[idx++])
        ;
    vector<int> ans = maxInWindows(num, size);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
