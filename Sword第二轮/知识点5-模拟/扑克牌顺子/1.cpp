/*
 * @Description: 扑克牌顺子。排序+判断
 * @Author: Mr. Lee
 * @Date: 2021-06-18 22:59:05
 * @LastEditTime: 2021-06-20 10:27:16
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsContinuous(vector<int> numbers)
{
    // 统计"0"牌的个数，以及记录不连续的牌之间的间隔
    int zeroofnum = 0, gap = 0;
    // 排序
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        if (!numbers[i])
        {
            // 统计"0"牌的个数
            zeroofnum++;
        }
        else
        {
            if (numbers[i] != numbers[i + 1])
            {
                // 统计牌与牌之间的间隔
                gap += (numbers[i + 1] - numbers[i] - 1);
            }
            else
            {
                // 如果有牌出现重复，那么一定无法构成顺子，直接返回false
                return false;
            }
        }
    }

    // 如果"0"牌的个数大于等于间隔，那么可以构成顺子
    return zeroofnum >= gap;
}

int main()
{
    // 测试用例
    // vector<int> numbers = {13, 12, 11, 0, 1};
    // bool ans = IsContinuous(numbers);
    // cout << boolalpha << ans << endl;

    // 手动输入
    vector<int> numbers(5);
    int idx = 0;
    while (cin >> numbers[idx++] && idx < 5)
        ;
    bool ans = IsContinuous(numbers);
    cout << boolalpha << ans << endl;

    return 0;
}