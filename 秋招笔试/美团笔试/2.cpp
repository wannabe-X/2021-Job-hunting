/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-11 15:58:55
 * @LastEditTime: 2021-09-11 17:06:41
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, m, q;
    cin >> n >> m >> q;
    int t1, t2;

    unordered_set<string> st;

    vector<int> nums(n, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> t1 >> t2;
        string path;
        path += (t1 > t2 ? to_string(t2) + '-' + to_string(t1) : to_string(t1) + '-' + to_string(t2));
        if (!st.count(path))
        {
            st.insert(path);
            nums[t1 - 1]++;
            nums[t2 - 1]++;
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> t1 >> t2;
        swap(nums[t1 - 1], nums[t2 - 1]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
