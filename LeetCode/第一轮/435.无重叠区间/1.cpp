#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0)
        return 0;
    // 先按照结束时间end排序
    sort(intervals.begin(), intervals.end(), cmp);

    // 按照end结束时间剔除
    int x_end = intervals[0][1], count = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        // cout << x_end << endl;
        if (intervals[i][0] < x_end)
            count++;
        else
            x_end = intervals[i][1];
    }

    return count;
}

int main()
{
    vector<vector<int>> internals = {{0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}};
    int ans = eraseOverlapIntervals(internals);
    cout << ans << endl;
    return 0;
}
