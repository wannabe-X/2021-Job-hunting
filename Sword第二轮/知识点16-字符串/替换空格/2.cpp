/*
 * @Description: 替换空格。包含去掉首尾空格
 * @Author: Mr. Lee
 * @Date: 2021-06-30 11:14:26
 * @LastEditTime: 2021-06-30 11:44:05
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string replaceSpace(string s)
{
    // 去掉首尾空格

    int i, j;

    // 去掉首空格
    for (i = 0; (i < s.size()) && (s[i] == ' '); i++)
        ;
    // 去掉尾空格
    for (j = s.size() - 1; (j >= 0) && (s[j] == ' '); j--)
        ;

    string res;
    for (int k = i; k < j + 1; k++)
    {
        if (s[k] == ' ')
            res += "%20";
        else
            res += s[k];
    }

    return res;
}

int main()
{
    // 测试用例
    // string str = "  hello   world    ";

    // 
    string str;
    getline(cin,str);
    string res = replaceSpace(str);
    cout << res << endl;

    return 0;
}
