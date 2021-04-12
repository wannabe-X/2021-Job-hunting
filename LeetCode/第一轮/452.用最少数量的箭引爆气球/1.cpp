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
    // �Ȱ��ս���ʱ��end����
    sort(intervals.begin(), intervals.end(), cmp);

    // ����end����ʱ���޳�
    int x_end = intervals[0][1], count = 1;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] > x_end)
        {
            count++;
            x_end = intervals[i][1];
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> internals = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int ans = eraseOverlapIntervals(internals);
    cout << ans << endl;
    return 0;
}
