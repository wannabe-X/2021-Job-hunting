/*
 * @Description: 替换空格
 * @Author: Mr. Lee
 * @Date: 2021-06-30 11:14:26
 * @LastEditTime: 2021-06-30 11:44:57
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string replaceSpace(string s)
{
    string res;
    for (int k = 0; k < s.size(); k++)
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
    getline(cin, str);
    string res = replaceSpace(str);
    cout << res << endl;

    return 0;
}
