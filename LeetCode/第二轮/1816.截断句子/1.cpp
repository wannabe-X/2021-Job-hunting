/*
 * @Description: 1816. 截断句子
 * @Author: Mr. Lee
 * @Date: 2021-12-06 00:04:34
 * @LastEditTime: 2021-12-06 00:34:00
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// 常规思路,按照空格进行拆分字符串,直到达到k个.然后,因为不包含尾空格,所以还对最后一个单词处理
// string truncateSentence(string s, int k)
// {
//     string res;
//     int i = 0, j = 0, count = 0;
//     for (; i < s.size() && count < k; i++)
//     {
//         if (s[i] == ' ')
//         {
//             res += s.substr(j, i - j);
//             count++;
//             j = i;
//         }
//     }

//     if (i == s.size() && count < k)
//         res += s.substr(j, i - j);

//     return res;
// }

// 使用IO分割空格,提取字符串
string truncateSentence(string s, int k)
{
    istringstream ss(s);
    string res;
    for (int i = 0; i < k; i++)
    {
        string tmp;
        ss >> tmp;
        res += (tmp + ' ');
    }
    res.pop_back();

    return res;
}

int main(int argc, char *argv[])
{
    string s = "What is the solution to this problem";
    int k = 4;
    string ans = truncateSentence(s, k);
    cout << ans << endl;

    return 0;
}