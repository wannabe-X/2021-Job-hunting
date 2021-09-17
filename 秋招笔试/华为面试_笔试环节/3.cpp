/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-16 15:25:10
 * @LastEditTime: 2021-09-17 19:37:00
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> func(string str)
{
    vector<int> res;
    for (int i(0); i < str.length(); ++i)
    {
        char c = str[i];
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            vector<int> left = func(str.substr(0, i));
            vector<int> right = func(str.substr(i + 1));
            for (int i : left)
            {
                for (int j : right)
                {
                    switch (c)
                    {
                    case '+':
                        res.push_back(i + j);
                        break;
                    case '-':
                        res.push_back(i - j);
                        break;
                    case '*':
                        res.push_back(i * j);
                        break;
                    case '/':
                        res.push_back(i / j);
                        break;
                    }
                }
            }
        }
    }

    if (res.empty())
        res.push_back(stoi(str));

    return res;
}

int main(void)
{
    string str;
    getline(cin, str);
    vector<int> ans = func(str);
    if (ans.size() == 1)
    {
        cout << ans[0] << endl;
        cout << ans[0] << endl;
    }
    else
    {
        cout << ans[0] << endl;
        cout << ans[ans.size() - 1] << endl;
    }

    return 0;
}