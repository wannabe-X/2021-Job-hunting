/*
 * @Description: 把数组排成最小的数
 * @Author: Mr. Lee
 * @Date: 2021-07-01 00:01:49
 * @LastEditTime: 2021-07-01 00:23:36
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 先排序，在使用动态规划
string PrintMinNumber(vector<int> numbers)
{
    string res;
    int sum = 0;
    sort(numbers.begin(), numbers.end());

    for (int num : numbers)
    {
        res = min(res + to_string(num), to_string(num) + res);
    }

    return res;
}

int main()
{
    // 测试用例
    // vector<int> array = {3334,3,3333332};
    // string ans = PrintMinNumber(array);

    int idx = 0, n;
    cin >> n;
    vector<int> array(n);
    while (idx < n && cin >> array[idx++])
        ;
    string ans = PrintMinNumber(array);
    cout << ans << endl;

    return 0;
}
