/*
 * @Description: 8. 字符串转换整数 (atoi)
 * @Author: Mr. Lee
 * @Date: 2021-07-18 15:17:04
 * @LastEditTime: 2021-07-18 15:55:50
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int myAtoi(string s)
{
    long long res = 0;
    int sign = 1;
    // 去掉前后空格
    s = s.erase(0, s.find_first_not_of(' ')).erase(s.find_last_not_of(' ') + 1);

    // 处理首字符
    int start = 0, end = s.size() - 1;
    if (s[0] == '+')
    {
        sign = 1;
        start++;
    }
    else if (s[0] == '-')
    {
        sign = -1;
        start++;
    }
    else if (!isdigit(s[0]))
    {
        return 0;
    }

    // 去掉数字前多余的0和后面的非数字符号
    for (; start < s.size() && (s[start] - '0' == 0); start++)
        ;
    for (end = start; end < s.size() && (isdigit(s[end])); end++)
        ;

    // 转化为数字
    for (int i = start; i < end && res < INT_MAX; i++)
    {
        res = res * 10 + (s[i] - '0');
    }

    if (res == INT_MAX)
    {
        if (sign == -1)
            res *= sign;
    }
    else if (res > INT_MAX)
    {
        res = INT_MAX;
        if (sign == -1)
            res = INT_MIN;
    }
    else
    {
        res *= sign;
    }

    return res;
}

int main()
{
    string s = "4193 with words";
    int ans = myAtoi(s);
    cout << ans << endl;

    return 0;
}