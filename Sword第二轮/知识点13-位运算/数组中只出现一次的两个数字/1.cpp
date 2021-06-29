/*
 * @Description: 数组中只出现一次的两个数字。使用哈希表
 * @Author: Mr. Lee
 * @Date: 2021-06-29 23:06:37
 * @LastEditTime: 2021-06-29 23:17:44
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> FindNumsAppearOnce(vector<int> &array)
{
    vector<int> res;
    map<int, int> m;
    for (int i = 0; i < array.size(); i++)
    {
        m[array[i]] += 1;
    }

    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        if ((*it).second == 1)
            res.push_back((*it).first);
    }
    return res;
}

int main()
{
    // 测试用例
    // vector<int> array = {1, 4, 1, 6};
    
    int n, idx = 0;
    cin >> n;
    vector<int> array(n);
    while (idx < n && cin >> array[idx++])
        ;
    vector<int> ans = FindNumsAppearOnce(array);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
