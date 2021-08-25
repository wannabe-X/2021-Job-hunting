/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-25 15:50:03
 * @LastEditTime: 2021-08-25 16:03:05
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> s;

    for (int i = n - 1; i > -1; i--)
    {
        while (!s.empty() && temperatures[s.top()] <= temperatures[i])
        {
            s.pop();
        }

        res[i] = s.empty() ? 0 : s.top() - i;

        s.push(i);
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> temperatures = {30, 40, 50, 40, 30, 60};
    vector<int> ans = dailyTemperatures(temperatures);
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}