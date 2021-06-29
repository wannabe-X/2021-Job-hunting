/*
 * @Description: 和为S的两个数字。双指针法
 * @Author: Mr. Lee
 * @Date: 2021-06-28 22:52:49
 * @LastEditTime: 2021-06-28 23:06:37
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
    int i = 0, j = array.size() - 1;
    while (i < j)
    {
        int tmp = array[i] + array[j];
        if (tmp > sum)
            j--;
        else if (tmp < sum)
            i++;
        else
            return {array[i], array[j]};
    }

    return {};
}

int main()
{
    // 测试代码
    // vector<int> array = {1, 2, 4, 7, 11, 15};
    // int num = 15;

    //
    int n, num;
    cin >> n >> num;
    vector<int> array(n);
    int idx = 0;
    while (idx < n && cin >> array[idx++])
        ;

    vector<int> ans = FindNumbersWithSum(array, num);
    if (ans.size() > 0)
        cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
