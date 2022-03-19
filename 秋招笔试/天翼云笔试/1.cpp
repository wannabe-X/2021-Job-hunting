/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2022-03-19 18:58:17
 * @LastEditTime: 2022-03-19 20:03:33
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int start, end;
};

int cmp(node x, node y)
{
    x.end == y.end ? x.start < y.start : x.end < y.end;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    node nums[n];
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int idx = str.find_first_of(',');
        nums[i].start = stoi(str.substr(0, idx));
        nums[i].end = stoi(str.substr(idx + 1, str.size() - idx - 1));
    }

    sort(nums, nums + n, cmp);

    int res = 0;
    int tmp = nums[0].start;
    for (int i = 0; i < n; i++)
    {
        if (nums[i].start >= tmp)
        {
            tmp = nums[i].end;
            res += nums[i].end - nums[i].start;
        }
    }
    cout << res << endl;

    return 0;
}
