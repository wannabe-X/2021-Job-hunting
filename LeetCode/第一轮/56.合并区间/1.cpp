#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n < 1)
        return {};

    vector<vector<int>> res;

    // 按照各区间[start,end]的start排序，从小到大
    sort(intervals.begin(), intervals.end());
    // 把start最小对应的区间放到res中
    res.push_back(intervals[0]);

    for (int i = 1; i < n; i++) // 注意i是从1开始的
    {
        vector<int> curvec = intervals[i];
        if (curvec[0] <= res.back()[1]) // 可以合并区间的情况，比较前一个区间的end和下一个区间start的大小
        {
            // 合并后的区间的end应该是前一个区间的end和后一个区间的end的最大值
            int max_end = max(res.back()[1], curvec[1]);
            res.back()[1] = max_end;
        }
        else // 不可以合并区间的情况
        {
            res.push_back(curvec);
        }
    }

    return res;
}

int main(void)
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = merge(intervals);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
}