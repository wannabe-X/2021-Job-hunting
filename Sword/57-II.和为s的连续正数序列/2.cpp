#include <iostream>
#include <vector>

using namespace std;

// 剑指offer参考解法
vector<int> continuousSequence(int small, int big)
{
    vector<int> temp;
    for (int i = small; i < big + 1; temp.push_back(i), i++)
        ;
    return temp;
}

vector<vector<int>> findContinuousSequence(int target)
{
    int small = 1, big = 2;
    int mid = (target + 1) / 2;
    int curSum = small + big;
    vector<vector<int>> res;
    while (small < mid)
    {
        if (curSum == target)
            res.push_back(continuousSequence(small, big));

        while (curSum > target && small < mid)
        {
            curSum -= small;
            small++;
            if (curSum == target)
                res.push_back(continuousSequence(small, big));
        }

        big++;
        curSum += big;
    }
    return res;
}

int main(void)
{
    int target = 2;
    vector<vector<int>> ans = findContinuousSequence(target);
    for (vector<int> tem : ans)
    {
        for (int num : tem)
            cout << num << ' ';
        cout << endl;
    }
    return 0;
}