/*
 * @Description: 把字符串转换成整数
 * @Author: Mr. Lee
 * @Date: 2021-06-27 20:09:32
 * @LastEditTime: 2021-06-27 21:58:17
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int StrToInt(string str)
{
    // 考虑字符串的长度小于2的情况，排除一位符号或者空字符串的形式
    if (str.size() < 2)
    {
        if (str.size() == 0)
            return 0;
        else
        {
            int num = (str[0] - '0');
            return (num < 10 && num > -1) ? num : 0;
        }
    }

    // 考虑字符串的长度大于等于2的情况
    int sym = 1, start = 0;
    long digit = 1, res = 0;
    if (str[0] == '0')
    {
        return 0;
    }
    else if (str[0] == '-')
    {
        sym = -1;
        start++;
    }
    else if (str[0] == '+')
    {
        start++;
    }

    // 排除+a/+0等非法数字
    if (start == 1)
    {
        int num = (str[1] - '0');
        if (num >= 10 || num == 0)
        {
            return 0;
        }
    }

    for (int i = start; i < str.size(); i++)
    {
        int num = (str[i] - '0');
        if (num >= 10)
        {
            return 0;
        }
        res = res * 10 + num;
    }

    res *= sym;

    return res;
}

int main()
{
    // 测试用例
    // string str = "+2147483647";

    string str;
    cin >> str;
    int ans = StrToInt(str);
    cout << ans << endl;

    return 0;
}
