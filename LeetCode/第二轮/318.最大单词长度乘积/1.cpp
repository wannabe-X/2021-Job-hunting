/*
 * @Description: 318. 最大单词长度乘积
 * @Author: Mr. Lee
 * @Date: 2021-11-17 10:28:00
 * @LastEditTime: 2021-11-17 17:35:53
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 使用位移(左移)运算来获取掩码,从而利用与运算判断是否有重复字母
int maxProduct(vector<string> &words)
{
    int res = 0;
    vector<int> mask(words.size(), 0);
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].size(); j++)
        {
            mask[i] |= (1 << (words[i][j] - 'a'));
        }
    }

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            if (!(mask[i] & mask[j]))
                res = max(res, int(words[i].size() * words[j].size()));
        }
    }

    return res;
}

int main(int argc, char **argv)
{
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    int ans = maxProduct(words);
    cout << ans << endl;

    return 0;
}