static bool comp(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    if (intervals.empty())
        return res;

    vector<int> tmp;

    sort(intervals.begin(), intervals.end(), comp);

    int i = 0;
    for (; i < intervals.size(); i++)
    {
        if (intervals[i][0] > tmp[1])
        {
            res.push_back(tmp);
            tmp = intervals[i];
        }
        else if (intervals[i][0] <= tmp[1])
        {
            tmp[1] = max(intervals[i][1], tmp[1]);
        }
    }

    if (res.back()[1] < intervals[intervals.size() - 1][0])
        res.push_back(intervals[intervals.size() - 1]);
    else
        res.back()[1] = max(res.back()[1], intervals[intervals.size() - 1][1]);

    return res;
}