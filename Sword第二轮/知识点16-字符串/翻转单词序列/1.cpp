/*
 * @Description: 翻转单词序列
 * @Author: Mr. Lee
 * @Date: 2021-07-02 16:56:44
 * @LastEditTime: 2021-07-02 17:29:34
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

string ReverseSentence(string str)
{
    str += " ";
    string res, tmp;
    for (int i = 0; i < str.size(); i++)
    {
        tmp += str[i];

        if (str[i] == ' ')
        {
            res = tmp + res;
            tmp.clear();
        }
    }

    res = res.substr(0, res.size() - 1);

    return res;
}

int main()
{
    string str = "nowcoder. a am I";
    string ans = ReverseSentence(str);
    cout << ans << endl;

    return 0;
}
