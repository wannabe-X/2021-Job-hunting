/*
 * @Description: 剑指 Offer II 005. 单词长度的最大乘积
 * @Author: Mr. Lee
 * @Date: 2021-08-12 15:50:13
 * @LastEditTime: 2021-08-12 17:08:28
 * @LastEditors: Mr. Lee
 */

// 暴力破解 超时的解法
#include <vector>
#include <iostream>

using namespace std;

int maxProduct(vector<string> &words)
{
    int n = words.size();
    vector<int> str2int(n);

    // 将各words中的每个word压缩成一个int，26个字母保证不会造成int溢出
    // 压缩过程：abcw -> 0010000000000000000000000111
    for (int i = 0; i < n; i++)
    {
        for (char c : words[i])
        {
            str2int[i] |= (1 << (c - 'a'));
        }
    }

    // 计算不重复word的乘积最大值
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if ((str2int[i] & str2int[j]) == 0)
                maxLen = max(maxLen, int(words[i].size() * words[j].size()));
        }
    }

    return maxLen;
}

int main()
{
    vector<string> words = {"abcw", "baz", "foo", "bar", "fxyz", "abcdef"};
    int ans = maxProduct(words);
    cout << ans << endl;

    return 0;
}