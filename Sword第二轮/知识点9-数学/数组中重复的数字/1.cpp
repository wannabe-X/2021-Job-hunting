/*
 * @Description:  数组中重复的数字
 * @Author: Mr. Lee
 * @Date: 2021-06-27 20:58:23
 * @LastEditTime: 2021-06-27 21:57:47
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int duplicate(vector<int> &numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] != i)
        {
            swap(numbers[i], numbers[numbers[i]]);
        }

        if (numbers[i] == i)
        {
            continue;
        }

        if (numbers[i] == numbers[numbers[i]])
        {
            return numbers[i];
        }
    }

    return -1;
}

int main()
{
    // 测试用例
    // vector<int> numbers = {2, 3, 1, 0, 2, 5, 3};

    int n, idx = 0;
    cin >> n;
    vector<int> numbers(n);
    while (idx < n && cin >> numbers[idx++])
        ;
    int ans = duplicate(numbers);
    cout << ans << endl;

    return 0;
}