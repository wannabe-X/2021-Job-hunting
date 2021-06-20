/*
 * @Description: 1239. 串联字符串的最大长度。迭代 + 位运算
 * @Author: Mr. Lee
 * @Date: 2021-06-19 22:39:59
 * @LastEditTime: 2021-06-19 23:51:18
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

// 使用 迭代 + 位运算 的方法
int maxLength(vector<string> &arr)
{
    vector<int> masks = {0};
    int res;
    for (auto &s : arr)
    {
        int checker = 0; // 用一个最大26位的数字记录arr每个子字符串中出现过的字符
        // 对于arr中的每个字符，都检查其合法性，判断是否有重复字符出现
        for (char ch : s)
        {
            int val = ch - 'a';       //把a-z的字符, 转换成 0-25的数字
            if ((checker >> val) & 1) // (1<<val)即得到对于bit位上的mask.  然后与 checker的位相与, 看是否为1
            {
                checker = 0;
                break;
            }
            checker |= (1 << val); //否则把这一位 置1
        }

        if (checker == 0)
        {
            continue;
        }

        int n = masks.size();
        for (int i = 0; i < n; i++)
        {
            int m = masks[i];       // 取出masks中的每一个字符串
            if ((checker & m) == 0) // 判断是否在m的基础上追加arr中的下一个子字符串
            {
                masks.push_back(m | checker);
                // _builtin_popcount() 计算一个 32 位无符号整数有多少个位为1
                res = max(res, __builtin_popcount(m | checker)); // 比较最大的
            }
        }
    }

    return res;
}

int main()
{
    vector<string> arr = {"un", "iq", "ue"};
    int ans = maxLength(arr);
    cout << ans << endl;

    return 0;
}
