/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-28 18:02:19
 * @LastEditTime: 2021-08-28 18:57:08
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string deletespace(string str)
{
    for (int i = 1, j = 1; str[i] != '\0';)
    {
        while (str[i] != ' ' && str[i] != '\0')
            i++;

        if (str[i] == '\0')
            break;

        for (j = 1; str[i + j] == ' '; j++)
            ;

        if (str[i + j] == '\0' || isdigit(str[i + j]) || isalpha(str[i + j]))
            str.replace(i, j, " ");
        else
        {
            str.replace(i, j, "");
        }

        while (str[i] == ' ')
        {
            i++;
        }
    }

    return str;
}

vector<string> func(string s)
{
    // 去掉首尾空格
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);

    int count1 = 0;
    string tmp = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]) || isalpha(s[i]))
        {
            tmp += s[i];
        }
        else if (s[i] == '-')
        {
            if ((isdigit(s[i - 1]) && isalpha(s[i + 1])) || (isdigit(s[i + 1]) && isalpha(s[i - 1])))
            {
                tmp += '-';
            }
        }
        else if (s[i] == ' ')
        {
            tmp += ' ';
        }
    }

    // 去掉单词间多余的空格
    s = deletespace(tmp);

    string tmp1 = "";
    vector<string> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
            tmp1 += s[i];
        else
        {
            v.push_back(tmp1);
            tmp1 = "";
        }
    }
    v.push_back(tmp1);

    // // 开始倒序
    // string ans = "";
    // for (int i = v.size() - 1; i > -1; i--)
    // {
    //     ans += v[i] + ' ';
    // }

    // ans.erase(ans.find_last_not_of(" ") + 1);

    return v;
}

// 输入：I am an 20-years  out--standing @ * -stu- dent
// 输出：dent stu standing out 20-years an am I
int main(int argc, char *argv[])
{
    // string s = "I am an 20-years  out--standing @ * -stu- dent";
    string s;
    cin >> s;
    vector<string> ans = func(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i];
    }

    return 0;
}