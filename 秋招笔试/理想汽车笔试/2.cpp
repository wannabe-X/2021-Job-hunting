/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-13 11:12:31
 * @LastEditTime: 2021-12-13 11:31:20
 * @LastEditors: Mr. Lee
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> split(const string &s, const string &seperator)
{
    vector<string> result;
    int i = 0;

    while (i != s.size())
    {
        //找到字符串中首个不等于分隔符的字母；
        int flag = 0;
        while (i != s.size() && flag == 0)
        {
            flag = 1;
            for (int x = 0; x < seperator.size(); ++x)
                if (s[i] == seperator[x])
                {
                    ++i;
                    flag = 0;
                    break;
                }
        }

        //找到又一个分隔符，将两个分隔符之间的字符串取出；
        flag = 0;
        int j = i;
        while (j != s.size() && flag == 0)
        {
            for (int x = 0; x < seperator.size(); ++x)
                if (s[j] == seperator[x])
                {
                    flag = 1;
                    break;
                }
            if (flag == 0)
                ++j;
        }

        if (i != j)
        {
            result.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    
    return result;
}

int main()
{
    string str, split_symbol;
    cin >> str >> split_symbol;
    vector<string> v = split(str, split_symbol); //可按多个字符来分隔;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        cout << (i + 1) << ":" << v[i] << endl;
}